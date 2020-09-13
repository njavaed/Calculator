#ifndef EXPR_TREE_H_
#define EXPR_TREE_H_

#include "Expr_Node.h"
class Eval_Expr_Tree;

/**
 * @class Expr_Tree
 *
 * The expression tree is evaluated in this class. It is a type of math expression
 */

class Expr_Tree
{
    public:
        /// Default constructor.
        Expr_Tree(void);

        /// Destructor.
        virtual ~Expr_Tree(void);

        /**
         * Gives the current node of the tree
         * 
         * @return      node of the tree
         */
        Expr_Node & get_expr_node(void);

        /**
         * sets a node in the expression tree
         * 
         * @param[in]       node        the node we want to insert in the tree
         */
        void set_expr_node(Expr_Node * node);

        /**
         * This is the heart of expression tree as it traverses through the tree
         * and evaluates all the nodes
         * 
         * @return      final result of evaluation
         */
        int eval();
    private:
        /// a pointer to keep track of current node
        Expr_Node * node_;
};

#include "Expr_Tree.cpp"
#endif  //  !defined EXPR_TREE_H_