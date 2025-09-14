#include "parse.hpp"
#include <cstring>
#include <cstdlib>

void parseInput(char *inputLine, Param &param) {
    param.clear();

    char *token = strtok(inputLine, " \t\n");
    while (token != nullptr) {
        if (strcmp(token, "<") == 0) {
            token = strtok(nullptr, " \t\n");
            if (token) param.setInputRedirect(token);
        } else if (strcmp(token, ">") == 0) {
            token = strtok(nullptr, " \t\n");
            if (token) param.setOutputRedirect(token);
        } else if (strcmp(token, "&") == 0) {
            param.setBackground(1);
        } else {
            param.addArgument(token);
        }
        token = strtok(nullptr, " \t\n");
    }
}
