#ifndef EXPR_NODE_VISITOR_H_
#define EXPR_NODE_VISITOR_H_

// Forward declare
class Addition_Node;
class Sub_Node;
class Multiply_Node;
class Divide_Node;
class Mod_Node;
class Number_Node;

/**
 * @class Expr_Node_Visitor
 *
 * Interface for visitor pattern
 */
class Expr_Node_Visitor
{
    public:
        /// Default constructor.
        Expr_Node_Visitor(void){};

        /// Destructor.
        virtual ~Expr_Node_Visitor(void){};

        /**
         * Visitor method for visiting add node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the addition node
         */ 
        virtual void Visit_Addition_Node (const Addition_Node & node) = 0;
        
        /**
         * Visitor method for visiting subtract node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the subtract node
         */ 
        virtual void Visit_Sub_Node (const Sub_Node & node) = 0;
        
        /**
         * Visitor method for visiting multiply node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the multiply node
         */ 
        virtual void Visit_Mul_Node (const Multiply_Node & node) = 0;
        
        /**
         * Visitor method for visiting divide node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the divide node
         */
        virtual void Visit_Div_Node (const Divide_Node & node) = 0;
        
        /**
         * Visitor method for visiting mod node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the mod node
         */ 
        virtual void Visit_Mod_Node (const Mod_Node & node) = 0;
        
        /**
         * Visitor method for visiting number node and evaluating 
         * the node using left and right nodes of parent node
         * 
         * @param[in]       node           pointer to the number node
         */ 
        virtual void Visit_Number_Node (const Number_Node & node) = 0;
};

#endif  // !define EXPR_NODE_VISITOR_H_