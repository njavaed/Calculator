// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
#include "Array.h"
#include "Stack.h"
#include <iostream>
#include <stdio.h>

template <typename T>
Stack <T>::Stack (void)
:   top_(-1),
    stack_size_(0),
    arr_(SIZE)
{
   
}

//
// Stack
//
// copy constructor
template <typename T>
Stack <T>::Stack (const Stack & stack)
:   top_(-1),
    stack_size_(0),
    arr_(SIZE)
{
    //this->arr_ = stack.arr_;
    this->top_ = stack.top_;
    this->stack_size_ = stack.stack_size_;

    for(int i = 0; i < this->size();i++)
    {
        this->arr_[i] = stack.arr_[i];
    }
    
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    
}//end destructor

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if(top_ == (arr_.size() - 1))
    {
        arr_.resize(this->stack_size_ + 100);
        //std::cout << "Stack is full" << std::endl;
    }
    top_++;
    arr_[top_] = element;
    stack_size_++;
    
}//end push

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(is_empty())
    {
        throw empty_exception();
    }
    top_ = top_ - 1;
    stack_size_ = stack_size_ - 1;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //check for self assignment
    if(this == &rhs){
        return *this;
    }
    if(this->stack_size_ < rhs.stack_size_)
    {
        this->arr_ = Array<T>(rhs.stack_size_);   
    }

    this->stack_size_ = rhs.stack_size_;
    
    for(size_t i = 0; i < this->size(); i++){
        this->arr_[i] = rhs.arr_[i];
    }

    //this->arr_ = rhs.arr_;
    this->top_ = rhs.top_;
    return *this;
    
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // COMMENT Just reset the variables instead popping each element, which
    // is expensive.
    // REPLY I rest the stack by setting top_ equal to -1 again
    
    this->top_ = -1;
    this->stack_size_ = 0;

}






