#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32

class Param {
private:
    char *inputRedirect;            // filename or NULL
    char *outputRedirect;           // filename or NULL
    int background;                 // 0 = false, 1 = true
    int argumentCount;              // number of tokens
    char *argumentVector[MAXARGS];  // array of strings

public:
    Param();
    ~Param();

    void setInputRedirect(char *input);
    void setOutputRedirect(char *output);
    void setBackground(int bg);
    void addArgument(char *arg);

    char* getInputRedirect() const;
    char* getOutputRedirect() const;
    int getBackground() const;
    int getArgumentCount() const;
    char** getArgumentVector();

    void clear();
    void printParams();
};

#endif
