#include "Number_Node.h"
#include "Expr_Node_Visitor.h"

Number_Node::Number_Node(int num)
:   num_(num)
{}

Number_Node::~Number_Node(void)
{}

int Number_Node::eval(void) const
{
    return num_;
}

void Number_Node::accept(Expr_Node_Visitor &v) const
{
    v.Visit_Number_Node(*this);
}