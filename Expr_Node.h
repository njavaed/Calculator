//component
#ifndef EXPR_NODE_H_
#define EXPR_NODE_H_

#include <iostream>

// forward declare
class Expr_Node_Visitor;

class Expr_Node
{
    public:
        Expr_Node(void){};
        virtual ~Expr_Node(void){};
        virtual int eval (void) const = 0 ;
        virtual void accept (Expr_Node_Visitor & v) const = 0;
};

#endif