// This class represents a node that has only one child

#ifndef UNARY_EXPR_NODE_H_
#define UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Unary_Expr_Node   :   public Expr_Node
{
    public:
        Unary_Expr_Node(void);                  // constructor
        virtual ~Unary_Expr_Node(void);         // destructor
        virtual int eval(void);                 // eval function
    protected:
        Expr_Node * child_;                     // data member that is a child
};

#include "Unary_Expr_Node.cpp"

#endif