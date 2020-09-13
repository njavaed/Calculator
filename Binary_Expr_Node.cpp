#include "Binary_Expr_Node.h"
//#include "Expr_Node_Visitor.h"

// constructor
Binary_Expr_Node::Binary_Expr_Node(void)
:   right_(0),
    left_(0)
{}

// virtual destructor
Binary_Expr_Node::~Binary_Expr_Node(void)
{
    delete this->left_;
    left_ = 0;
    delete this->right_;
    right_ = 0;
}

void Binary_Expr_Node::accept(Expr_Node_Visitor & v) const
{
    // accept defined in sub classes
}

int Binary_Expr_Node::eval() const
{
    return 0;
}

 Expr_Node * Binary_Expr_Node::get_left() const
{
    return this->left_;
}

Expr_Node * Binary_Expr_Node::get_right() const
{
    return this->right_;
}

void Binary_Expr_Node::set_left(Expr_Node * left)
{
    this->left_ = left;
}
void Binary_Expr_Node::set_right(Expr_Node * right)
{
    this->right_ =  right;
}