#include "Calculator.h"
#include "Expr_Tree.h"
#include <sstream>
#include <string>
#include <iostream>

Calculator::Calculator(Expr_Builder & builder)
:   builder_(builder)
{}

int Calculator::evaluate(const std::string & infix)
{
    if(invalid_infix(infix))
    {
        throw std::runtime_error ("Bad expression");
    }
    if(infix.empty())
    {
        throw std::runtime_error ("No expression");
    }

    std::string postfix = infix_to_postfix(infix);
    parse_expr(postfix);
    return builder_.get_expression()->eval();
}


// checks the validity of infix expression
bool Calculator::invalid_infix(std::string expression)
{
    int bracket_sum = 0;    // number of brackets
    int numbers = 0;        // number of numbers
    int operators = 0;      // number of operators
    std::string current_token = "";
    std::string prev_token = "";

    std::istringstream ss (expression);
    std::string token;

    // parse the infix expression and update the above variables accordingly
    while(!ss.eof())
    {
        ss >> token;
        if(token == "(")
        {
            bracket_sum++;
        }
        else if(token == ")")
        {
            bracket_sum--;
        }
        else if(isOperator(token))
        {
            operators++;
        }
        else
        {
            numbers++;
            if(!isOperator(prev_token) && prev_token != "" && prev_token != "(" && prev_token != ")")
            {
                return true;
            }
            
        }
        prev_token = token;
    }
    // a check for validity
    if(numbers == operators || operators > numbers || bracket_sum != 0)
    {
        return true;
    }
    return false;
}

int Calculator::precedence(std::string command)
{
    if(command == "*" || command == "/" || command == "%")
    {
        return 2;
    }
    else if(command == "+" || command == "-")
    {
        return 1;
    }
    return 0;
}

bool Calculator::higher_precedence(std::string command, std::string current_token)
{
    if(precedence(command) >= precedence(current_token) )
    {
        return true;
    }

    return false; 
}

bool Calculator::isOperator(std::string op)
{
    if(op == "+" || op == "-" || op == "*" || op == "%" || op == "/")
    {
        return true;
    }
    return false;
}

std::string Calculator::infix_to_postfix(std::string infix)
{
    std::istringstream input (infix);
    std::string token;

    Stack <std::string> stack;
    std::string postfix_helper = "";

    while(!input.eof())
    {
        input >> token;
        // check if the token is an operator
        if(isOperator(token))
        {
            // if stack is not empty and the token on top of stack has higher precedence than current token and token is not an open parenthesis then append top of stack
            // to postfix expression and pop stack once
            while(!stack.is_empty() && higher_precedence(stack.top(), token) && stack.top() != "(")
            {
                postfix_helper = postfix_helper + " " + stack.top();
                stack.pop();
            }
            stack.push(token); // after popping stack push the current token to stack
        }
        else if(token == "(") 
        {
            stack.push(token);
        }
        // if it is closed parenthesis then append everything on the stack to the postfix until stack is empty
        else if(token == ")")
        {
            while(!stack.is_empty() && stack.top() != "(")
            {
                postfix_helper = postfix_helper + " " + stack.top();
                stack.pop();
            }
            // an extra pop to get rid of last opening parenthesis from stack
            stack.pop();  
        }
        else
        {
            postfix_helper = postfix_helper + " " + token;
        }
    } // end for

    while(!stack.is_empty())
    {
        postfix_helper = postfix_helper + " " + stack.top();
        stack.pop();
    }
    return postfix_helper;
}

bool Calculator::parse_expr(const std::string & parse_postfix)
{
    std::istringstream input(parse_postfix);
    std::string token;
    int number;

    builder_.start_expression();

    while(!input.eof())
    {
        input >> token;
        if(token == "+")
        {
            this->builder_.build_add();
        }
        else if(token == "-")
        {
            this->builder_.build_sub();
        }
        else if(token == "*")
        {
            this->builder_.build_mul();
        }
        else if(token == "/")
        {
            this->builder_.build_div();
        }
        else if(token == "%")
        {
            this->builder_.build_mod();
        }
        else
        {
            number = stoi(token);
            this->builder_.build_num(number);
        }
        
    }
    return true;
}