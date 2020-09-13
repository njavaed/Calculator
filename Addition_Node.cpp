#include "Addition_Node.h"
#include "Expr_Node_Visitor.h"

Addition_Node::Addition_Node(void)
{}

Addition_Node::Addition_Node(Expr_Node * num1, Expr_Node * num2)
{
    this->left_  = num1;
    this->right_ = num2;
}

Addition_Node::~Addition_Node(void)
{}

void Addition_Node::accept(Expr_Node_Visitor & v) const
{
    v.Visit_Addition_Node(*this);
}


