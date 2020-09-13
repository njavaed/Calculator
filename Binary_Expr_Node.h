#ifndef BINARY_EXPR_NODE_H_
#define BINARY_EXPR_NODE_H_
#include <iostream>

class Expr_Node_Visitor;
#include "Expr_Node.h"

/**
 * @class Binary_Expr_Node
 *
 * Lets the binary operators set and get their children. 
 * It is a composite.
 */
class Binary_Expr_Node  : public Expr_Node
{
    public:
        /// Default constructor.
        Binary_Expr_Node(void); 
        
         /// Destructor.                                               
        virtual ~Binary_Expr_Node(void);

        /**
         * Evaluate a node. This is here so that this class
         * is not considered abstract.
         */     
        virtual int eval() const;

        /**
         * Accepts a visitor on its node
         * 
         * @param[in]       v           reference to a visitor class to visit add node
         */  
        virtual void accept (Expr_Node_Visitor & v) const;   

        /**
         * The left node of the binary operator
         * 
         * @return      the node on the left
         */
        Expr_Node * get_left() const;

        /**
         * The right node of the binary operator
         * 
         * @return      the node on the right
         */
        Expr_Node * get_right() const;

        /**
         * sets the left node of the binary operator
         * 
         * @param[in]      left     the node to be set on left
         */
        void set_left(Expr_Node * left);

        /**
         * sets the right node of the binary operator
         * 
         * @param[in]      right     the node to be set on right
         */
        void set_right(Expr_Node * right);

    protected:   
        /// a pointer to node on left
        Expr_Node * left_;  

        /// a pointer to node on right
        Expr_Node * right_;
        
};

#include "Binary_Expr_Node.cpp"

#endif  // !defined BINARY_EXPR_NODE_H_