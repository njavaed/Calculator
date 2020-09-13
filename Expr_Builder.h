#ifndef EXPR_BUILDER_H_
#define EXPR_BUILDER_H_
#include "Expr_Tree.h"


/**
 * @class Expr_Builder
 *
 * An interface for builder pattern
 */
class Expr_Builder 
{
    public:
        /// Default constructor.
        Expr_Builder(void){};

        /// Destructor.
        virtual ~Expr_Builder(void){};

        /**
         * Initializes a tree on the heap
         */
        virtual void start_expression(void) = 0;

        /**
         * builds the number command on the heap and adds
         * it to stack
         * 
         * @param[in]       n       number
         */
        virtual void build_num(int n) = 0;

        /**
         * Pops the top two number nodes from the stack and
         * create an add node on the heap with these number nodes as input
         * Then sets this add node as a node in tree
         * Also pushes this add node to stack.
         *
         */
        virtual void build_add(void) = 0;

        /**
         * Pops the top two number nodes from the stack and
         * create a subtract node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_sub(void) = 0;
        
        /**
         * Pops the top two number nodes from the stack and
         * create a multiply node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_mul(void) = 0;
        
        /**
         * Pops the top two number nodes from the stack and
         * create a mod node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_mod(void) = 0;
        
        /**
         * Pops the top two number nodes from the stack and
         * create a divide node on the heap with these number nodes as input
         * Then sets this add node as a node in tree 
         * Also pushes this add node to stack.
         */
        virtual void build_div(void) = 0;

        /**
         * Gives the final expression tree
         * 
         * @return      expression tree
         */
        virtual Expr_Tree * get_expression(void) = 0;

        /**
         * To delete the tree after every evalaution
         */
        virtual void end_expression(void) = 0;
};

#endif  // !defined EXPR_BUILDER_H_