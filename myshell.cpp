#include "parse.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    bool debugMode = false;
    if (argc == 2 && strcmp(argv[1], "-Debug") == 0) {
        debugMode = true;
    }

    Param param;
    std::string line;

    while (true) {
        std::cout << "$$$ ";
        if (!std::getline(std::cin, line)) break;

        if (line == "exit") {
            // prevent zombies by terminating them at exit time
            while (waitpid(-1, nullptr, WNOHANG) > 0 ) {} 
            break;
        }

        char *cstr = strdup(line.c_str());
        parseInput(cstr, param);
        free(cstr);

        if (debugMode) {
            param.printParams();
        }

        // Only execute if there is at least one argument
        if (param.getArgumentCount() > 0) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork failed");
                continue;
            } else if (pid == 0) {
                // Redirects input to a file if specified
                if (param.getInputRedirect()) {
                    freopen(param.getInputRedirect(), "r", stdin);
                }
                // Redirects output to a file if specified
                if (param.getOutputRedirect()) {
                    freopen(param.getOutputRedirect(), "w", stdout);
                }
                // Execute command
                char **args = param.getArgumentVector();
                execvp(args[0], args);
                // If execvp returns, throws error and terminates process
                perror("execvp failed");
                exit(1);
            } else {
                // Parent process
                if (!param.getBackground()) {
                    // Wait for child if not background
                    waitpid(pid, nullptr, 0);
                }
            }
        }
    }

    return 0;
}
