#ifndef EVAL_EXPR_TREE_H_
#define EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"
#include "Stack.h"
class Addition_Node;
class Sub_Node;
class Multiply_Node;
class Divide_Node;
class Mod_Node;
class Number_Node;

/**
 * @class Eval_Expr_Tree
 *
 * The evaluation operation to implement visitor pattern
 * Inherits from Expr_Node_Visitor
 */
class Eval_Expr_Tree    :   public Expr_Node_Visitor
{
    public:
        /// Default constructor.
        Eval_Expr_Tree(void);

        /// Destructor.
        virtual ~Eval_Expr_Tree(void);

        /**
         * Visitor method for visiting add node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the addition node
         */ 
        virtual void Visit_Addition_Node (const Addition_Node & node);

        /**
         * Visitor method for visiting subtract node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the subtract node
         */ 
        virtual void Visit_Sub_Node (const Sub_Node & node);

        /**
         * Visitor method for visiting multiply node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the multiply node
         */ 
        virtual void Visit_Mul_Node (const Multiply_Node & node);

        /**
         * Visitor method for visiting divide node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the divide node
         */ 
        virtual void Visit_Div_Node (const Divide_Node & node);

        /**
         * Visitor method for visiting mod node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the mod node
         */ 
        virtual void Visit_Mod_Node (const Mod_Node & node);

        /**
         * Visitor method for visiting number node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the number node
         */ 
        virtual void Visit_Number_Node (const Number_Node & node);

        /**
         * Give sthe result of the evaluation from above visitor methods
         * 
         * @return       value of the result
         */ 
        int result(void) const;
    
        private:
            // keeps track of the result of the evaluation
            int result_;

};

#include "Eval_Expr_Tree.cpp"

#endif  // !defined EVAL_EXPR_TREE_H_