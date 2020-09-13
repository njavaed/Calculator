#include <iostream>
#include "Expr_Tree_Builder.h"
#include "Calculator.h"

int main()
{
    Expr_Tree_Builder build;
    Calculator calc(build);

    bool keepGoing = true;
    while(keepGoing)
    {
        std::string infix;
        std::cout << "Enter an expression to calculate or enter QUIT to exit" << std::endl;
        std::getline(std::cin, infix);

        if(infix == "QUIT" || infix == "quit")
        {
            keepGoing = false;
        }
        else
        {
            std::cout << "result: " << calc.evaluate(infix) << std::endl;
        }
        build.end_expression();
    }
    return 0;
}