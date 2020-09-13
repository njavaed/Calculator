#include "Unary_Expr_Node.h"

Unary_Expr_Node::Unary_Expr_Node(void)
:   child_(0)
{}

Unary_Expr_Node::~Unary_Expr_Node(void)
{}

int Unary_Expr_Node::eval(void)
{
    // if it is the only child then apply eval function on this child and return it
    if(this->child_)
    {
        return this->child_->eval();
    }
}