#include "Divide_Node.h"
#include "Expr_Node_Visitor.h"

Divide_Node::Divide_Node(void)
{}

Divide_Node::Divide_Node(Expr_Node * num1, Expr_Node * num2)
{
    this->left_  = num1;
    this->right_ = num2;
}

Divide_Node::~Divide_Node(void)
{}

void Divide_Node::accept(Expr_Node_Visitor & v) const
{
    v.Visit_Div_Node(*this);
}


