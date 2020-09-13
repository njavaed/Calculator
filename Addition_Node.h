#ifndef ADDITION_NODE_H_
#define ADDITION_NODE_H_

// Forward declare
class Expr_Node_Visitor;
#include "Binary_Expr_Node.h"
#include "Expr_Node.h"

/**
 * @class Addition_Node
 *
 * An addition node that accepts operation on it
 * public inheritance from Binary_Expr_Node
 */
class Addition_Node : public Binary_Expr_Node
{
    public:
        /// Default constructor.
        Addition_Node(void);

        /**
         * Initializing constructor.
         *
         * @param[in]      num1        left node or number on left side of this node
         * @param[in]      num1        right node or number on right side of this node
         */
        Addition_Node(Expr_Node * num1, Expr_Node * num2);
        
        /// Destructor.
        virtual ~Addition_Node(void); 

        /**
         * Accepts a visitor on its node
         * 
         * @param[in]       v           reference to a visitor class to visit this node
         */                 
        virtual void accept (Expr_Node_Visitor & v) const;
};

#include "Addition_Node.cpp"

#endif  // !defined ADDITION_NODE_H_