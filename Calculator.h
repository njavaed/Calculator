#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include "Expr_Builder.h"
#include "Stack.h"


/**
 * @class Calculator
 *
 * This class is the director of builder pattern. 
 * It takes an expression, parse it through builder 
 * and evaluates it for the client.
 */
class Calculator
{
    public:
        /**
         * Initializing constructor.
         *
         * @param[in]      builder        a pointer to Expr_Builder class
         */
        Calculator(Expr_Builder & builder);

        /**
         * Evalautes the infix expression by parsing it through builder
         * Converts the infix to expression tree and evaluates it
         * 
         * @param[in]       infix          a pointer to infix expression
         */  
        int evaluate(const std::string & infix);

        /**
         * Parses the postfix expression to convert to expression tree
         * 
         * @param[in]       parse_postfix          postfix expression
         */  
        bool parse_expr(const std::string & parse_postfix);
        
        /**
         * Checks if the infix expression is valid or not
         * 
         * @param[in]       expression          infix expression
         */
        bool invalid_infix(std::string expression);

        /**
         * Checks if a string is an operator or not
         * 
         * @param[in]       op          operator string
         */
        bool isOperator(std::string op);

        /**
         * Determines the precedence value of an operator given a string
         * 
         * @param[in]       command          command string
         * 
         * @return          precedence value
         */
        int precedence(std::string command);

        /**
         * Checks if current token has highr precedence than token on top of stack
         * 
         * @param[in]       command          command string
         * @param[in]       current_token    the current token string in infix expression
         * 
         * @return          true or false
         */
        bool higher_precedence(std::string command, std::string current_token);
        
        /**
         * Converts infix expression to postfix expression
         * 
         * @param[in]       infix          expression
         * 
         * @return          postfix expression
         */
        std::string infix_to_postfix(std::string infix);

    private:
        /// a pointer to Expr_Builder class
        Expr_Builder & builder_;
};

#include "Calculator.cpp"

#endif  // !defined CALCULATOR_H_
