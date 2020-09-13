#ifndef DIVIDE_NODE_H_
#define DIVIDE_NODE_H_

class Expr_Node_Visitor;
#include "Binary_Expr_Node.h"
#include "Expr_Node.h"

/**
 * @class Divide_Node
 *
 * A divide node that accepts operation on it
 * public inheritance from Binary_Expr_Node
 */
class Divide_Node : public Binary_Expr_Node
{
    public:
        /// Default constructor.
        Divide_Node(void);

        /**
         * Initializing constructor.
         *
         * @param[in]      num1        left node or number on left side of node
         * @param[in]      num1        right node or number on right side of node
         */
        Divide_Node(Expr_Node * num1, Expr_Node * num2);

        /// Destructor.
        virtual ~Divide_Node(void);

        /**
         * Accepts a visitor on its node
         * 
         * @param[in]       v           reference to a visitor class to visit this node
         */ 
        virtual void accept (Expr_Node_Visitor & v) const; 

};

#include "Divide_Node.cpp"

#endif  // !defined DIVIDE_NODE_H_