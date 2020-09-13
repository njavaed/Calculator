#ifndef NUMBER_NODE_H_
#define NUMBER_NODE_H_

class Expr_Node_Visitor;
#include "Expr_Node.h"


/**
 * @class Number_Node
 *
 * A number node that accepts operation on it
 * public inheritance from Expr_Node
 */
class Number_Node   :   public Expr_Node
{
    public:
        /**
         * Initializing constructor.
         *
         * @param[in]      num        number to set as node in tree
         
         */
        Number_Node(int num);

        /// Destructor.
        virtual ~Number_Node(void);

        /**
         * Retrive the number from number node
         * 
         * @return      number to be retrieved
         */
        virtual int eval(void) const;

        /**
         * Accepts a visitor on its node
         * 
         * @param[in]       v           reference to a visitor class to visit this node
         */ 
        virtual void accept(Expr_Node_Visitor &v) const;
        
    private:
        int num_;
};

#include "Number_Node.cpp"

#endif  // !defined NUMBER_NODE_H_
