#include "Mod_Node.h"
#include "Expr_Node_Visitor.h"

Mod_Node::Mod_Node(void)
{}

Mod_Node::Mod_Node(Expr_Node * num1, Expr_Node * num2)
{
    this->left_  = num1;
    this->right_ = num2;
}

Mod_Node::~Mod_Node(void)
{}

void Mod_Node::accept(Expr_Node_Visitor & v) const
{
    v.Visit_Mod_Node(*this);
}
