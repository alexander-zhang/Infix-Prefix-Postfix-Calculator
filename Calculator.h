#ifndef Calculator_h
#define Calculator_h

#include "StacksAndQueue.h"


class Calculator
{
private:
    bool valid;
    std::string infixEquation;
    std::string prefixEquation;
    std::string postfixEquation;


    double postResult;
    double preResult;

protected:
    bool isValidOp(char);
    bool isInteger(char);
    int priority(char);
    std::string reverse(std::string);

    std::string infixToPostfix(std::string);
    std::string infixToPostfixPRE(std::string);
    std::string infixToPrefix(std::string);
    double evalPostfix();
    double evalPrefix();
public:

    void setEquation(std::string);

    bool checkValidEqn(std::string);

    std::string getInfixEquation();
    std::string getPrefixEquation();
    std::string getPostfixEquation();

    double getPreResult();
    double getPostResult();
};

#endif /* Calculator_h */
