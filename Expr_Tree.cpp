#include "Expr_Tree.h"
#include "Eval_Expr_Tree.h"

Expr_Tree::Expr_Tree(void)
{
    node_ = 0;
}

Expr_Tree::~Expr_Tree(void)
{
    delete this->node_;
    node_ = 0;
}

// get a node from expression tree
Expr_Node & Expr_Tree::get_expr_node()
{
    return *this->node_;
}

// set a node of an expression tree
void Expr_Tree::set_expr_node(Expr_Node * node_X)
{
    node_ = node_X;
}

// evaluate the result of a node in expression tree
int Expr_Tree::eval()
{
    Expr_Node * expr_node = node_;
    Eval_Expr_Tree eval_expr;
    expr_node->accept(eval_expr);
    
    return eval_expr.result();
}