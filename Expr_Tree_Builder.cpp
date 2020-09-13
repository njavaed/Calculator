#include "Expr_Tree_Builder.h"
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Sub_Node.h"
#include "Divide_Node.h"
#include "Multiply_Node.h"
#include "Mod_Node.h"


Expr_Tree_Builder::Expr_Tree_Builder(void)
{}

Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
    delete this->tree_;
    this->tree_ = 0;
}

void Expr_Tree_Builder::start_expression(void)
{
    this->tree_ = new Expr_Tree;
}

void Expr_Tree_Builder::build_num(int n)
{
    Number_Node * num_node = new Number_Node(n);
    tree_->set_expr_node(num_node);
    stack_.push(num_node);
}

void Expr_Tree_Builder::build_add(void)
{ 
    Expr_Node * node1 = stack_.top();
    stack_.pop();
    Expr_Node * node2 = stack_.top();
    stack_.pop();
    Addition_Node * add = new Addition_Node(node2, node1); 
    tree_->set_expr_node(add);
    stack_.push(add);
}

void Expr_Tree_Builder::build_sub(void)
{
    Expr_Node * node1 = stack_.top();
    stack_.pop();
    Expr_Node * node2 = stack_.top();
    stack_.pop();
    Sub_Node * sub = new Sub_Node(node2, node1);  
    tree_->set_expr_node(sub);
    stack_.push(sub);
}


void Expr_Tree_Builder::build_mul(void)
{
    Expr_Node * node1 = stack_.top();
    stack_.pop();
    Expr_Node * node2 = stack_.top();
    stack_.pop();
    Multiply_Node * mul = new Multiply_Node(node2, node1);  
    tree_->set_expr_node(mul);
    stack_.push(mul);
}

void Expr_Tree_Builder::build_mod(void)
{
    Expr_Node * node1 = stack_.top();
    stack_.pop();
    Expr_Node * node2 = stack_.top();
    stack_.pop();
    Mod_Node * mod = new Mod_Node(node2, node1);  
    tree_->set_expr_node(mod);
    stack_.push(mod);
}

void Expr_Tree_Builder::build_div(void)
{
    Expr_Node * node1 = stack_.top();
    stack_.pop();
    Expr_Node * node2 = stack_.top();
    stack_.pop();
    Divide_Node * div = new Divide_Node(node2, node1);  
    tree_->set_expr_node(div);
    stack_.push(div);
}

Expr_Tree * Expr_Tree_Builder::get_expression(void)
{
    return this->tree_;
}

void Expr_Tree_Builder::end_expression(void)
{
    delete tree_;
    tree_ = 0;
}