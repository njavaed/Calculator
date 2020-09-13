#ifndef EXPR_TREE_BUILDER_H_
#define EXPR_TREE_BUILDER_H_
#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Binary_Expr_Node.h"


/**
 * @class Expr_Tree_Builder
 *
 * A concrete class of interface Expr_Builder
 * This class implements all the build commands
 */
class Expr_Tree_Builder : public Expr_Builder
{
    public:
        /// Default constructor.
        Expr_Tree_Builder(void);

        /// Destructor.
        virtual ~Expr_Tree_Builder(void);

        /**
         * Initializes a tree on the heap
         */
        virtual void start_expression(void);

        /**
         * builds the number command on the heap and adds
         * it to stack
         * 
         * @param[in]       n       number
         */
        virtual void build_num(int n);

        /**
         * Pops the top two number nodes from the stack and
         * create an add node on the heap with these number nodes as input
         * Then sets this add node as a node in tree
         * Also pushes this add node to stack.
         *
         */
        virtual void build_add(void);

        /**
         * Pops the top two number nodes from the stack and
         * create a subtract node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_sub(void);

        /**
         * Pops the top two number nodes from the stack and
         * create a multiply node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_mul(void);

        /**
         * Pops the top two number nodes from the stack and
         * create a mod node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_mod(void);

        /**
         * Pops the top two number nodes from the stack and
         * create a divide node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_div(void);

        /**
         * Gives the final expression tree
         * 
         * @return      expression tree
         */
        virtual Expr_Tree * get_expression(void);

        /**
         * To delete the tree after every evalaution
         */
        virtual void end_expression(void);

        private:
            // the expression tree
            Expr_Tree * tree_;

            // keeps track of nodes
            Stack <Expr_Node *> stack_;
        
};

#include "Expr_Tree_Builder.cpp"
#endif  // !defined EXPR_TREE_BUILDER_H_