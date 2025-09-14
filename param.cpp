#include "param.hpp"
#include <iostream>
#include <cstring>

Param::Param() {
    inputRedirect = nullptr;
    outputRedirect = nullptr;
    background = 0;
    argumentCount = 0;
    for (int i = 0; i < MAXARGS; i++) {
        argumentVector[i] = nullptr;
    }
}

Param::~Param() {
    clear();
}

void Param::setInputRedirect(char *input) {
    inputRedirect = input ? strdup(input) : nullptr;
}

void Param::setOutputRedirect(char *output) {
    outputRedirect = output ? strdup(output) : nullptr;
}

void Param::setBackground(int bg) {
    background = bg;
}

void Param::addArgument(char *arg) {
    if (argumentCount < MAXARGS) {
        argumentVector[argumentCount++] = strdup(arg);
    }
}

char* Param::getInputRedirect() const { return inputRedirect; }
char* Param::getOutputRedirect() const { return outputRedirect; }
int Param::getBackground() const { return background; }
int Param::getArgumentCount() const { return argumentCount; }
char** Param::getArgumentVector() { return argumentVector; }

void Param::clear() {
    if (inputRedirect) { free(inputRedirect); inputRedirect = nullptr; }
    if (outputRedirect) { free(outputRedirect); outputRedirect = nullptr; }
    for (int i = 0; i < argumentCount; i++) {
        free(argumentVector[i]);
        argumentVector[i] = nullptr;
    }
    argumentCount = 0;
    background = 0;
}

void Param::printParams() {
    std::cout << "Argument Count: " << argumentCount << "\n";
    for (int i = 0; i < argumentCount; i++) {
        std::cout << "Arg[" << i << "]: " << argumentVector[i] << "\n";
    }
    std::cout << "Input Redirect: " << (inputRedirect ? inputRedirect : "NULL") << "\n";
    std::cout << "Output Redirect: " << (outputRedirect ? outputRedirect : "NULL") << "\n";
    std::cout << "Background: " << background << "\n";
}
