#include "Sub_Node.h"
#include "Expr_Node_Visitor.h"

Sub_Node::Sub_Node(void)
{}

Sub_Node::Sub_Node(Expr_Node * num1, Expr_Node * num2)
{
    this->left_  = num1;
    this->right_ = num2;
}

Sub_Node::~Sub_Node(void)
{}

void Sub_Node::accept(Expr_Node_Visitor & v) const
{
    v.Visit_Sub_Node(*this);
}