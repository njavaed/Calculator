#ifndef MOD_NODE_H_
#define MOD_NODE_H_

class Expr_Node_Visitor;
#include "Binary_Expr_Node.h"
#include "Expr_Node.h"


/**
 * @class Mod_Node
 *
 * A mod node that accepts operation on it
 * public inheritance from Binary_Expr_Node
 */
class Mod_Node : public Binary_Expr_Node
{
    public:
        /// Default constructor.
        Mod_Node(void);

        /**
         * Initializing constructor.
         *
         * @param[in]      num1        left node or number on left side of this node
         * @param[in]      num1        right node or number on right side of this node
         */
        Mod_Node(Expr_Node * num1, Expr_Node * num2);                           
        
        /// Destructor.
        virtual ~Mod_Node(void);  

        /**
         * Accepts a visitor on its node
         * 
         * @param[in]       v           reference to a visitor class to visit this node
         */                 
        virtual void accept (Expr_Node_Visitor & v) const;

};

#include "Mod_Node.cpp"

#endif  // !defined MOD_NODE_H_