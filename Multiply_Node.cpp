#include "Multiply_Node.h"
#include "Expr_Node_Visitor.h"

Multiply_Node::Multiply_Node(void)
{}

Multiply_Node::Multiply_Node(Expr_Node * num1, Expr_Node * num2)
{
    this->left_  = num1;
    this->right_ = num2;
}

Multiply_Node::~Multiply_Node(void)
{}

void Multiply_Node::accept(Expr_Node_Visitor & v) const
{
    v.Visit_Mul_Node(*this);
}


