#include "Eval_Expr_Tree.h"
#include "Addition_Node.h"
#include "Sub_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Mod_Node.h"
#include "Number_Node.h"

Eval_Expr_Tree::Eval_Expr_Tree(void)
: result_(0)
{}

Eval_Expr_Tree::~Eval_Expr_Tree(void)
{}

void Eval_Expr_Tree::Visit_Addition_Node(const Addition_Node &node)
{
    // COMMENT You are supposed to call accept on the left and right node.
    // REPLY I have now called accept on the left and right nodes

    // visit left node, visit right node, call accept and then perform addition
    Expr_Node * num1 = node.get_left();
    Expr_Node * num2 = node.get_right();

    num1->accept(*this);
    int left_number  = this->result();
    num2->accept(*this);
    int right_number = this->result();
    
    this->result_ = left_number + right_number;
}

void Eval_Expr_Tree::Visit_Sub_Node(const Sub_Node & node)
{
    // COMMENT You are supposed to call accept on the left and right node.
    // REPLY I have now called accept on the left and right nodes

    Expr_Node * num1 = node.get_left();
    Expr_Node * num2 = node.get_right();

    num1->accept(*this);
    int left_number  = this->result();
    num2->accept(*this);
    int right_number = this->result();
    
    this->result_ = left_number - right_number;
}

void Eval_Expr_Tree::Visit_Mul_Node(const Multiply_Node & node)
{
    Expr_Node * num1 = node.get_left();
    Expr_Node * num2 = node.get_right();

    num1->accept(*this);
    int left_number  = this->result();
    num2->accept(*this);
    int right_number = this->result();

    this->result_ = left_number * right_number;
}

void Eval_Expr_Tree::Visit_Div_Node(const Divide_Node & node)
{
    Expr_Node * num1 = node.get_left();
    Expr_Node * num2 = node.get_right();

    num1->accept(*this);
    int left_number  = this->result();
    num2->accept(*this);
    int right_number = this->result();

    if(right_number == 0)
    {
        throw std::exception();
    }

    this->result_ = left_number / right_number;
}

void Eval_Expr_Tree::Visit_Mod_Node(const Mod_Node & node)
{
    Expr_Node * num1 = node.get_left();
    Expr_Node * num2 = node.get_right();

    num1->accept(*this);
    int left_number  = this->result();
    num2->accept(*this);
    int right_number = this->result();
    
    if(right_number == 0)
    {
        throw std::exception();
    }

    this->result_ = left_number % right_number;
}

void Eval_Expr_Tree::Visit_Number_Node(const Number_Node & node)
{
    this->result_ = node.eval();
}

int Eval_Expr_Tree::result(void) const
{
    return this->result_;
}




