#include "parse.hpp"
#include <iostream>
#include <string>
#include <cstring>

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

        if (line == "exit") break;

        char *cstr = strdup(line.c_str());
        parseInput(cstr, param);
        free(cstr);

        if (debugMode) {
            param.printParams();
        }
    }

    return 0;
}
