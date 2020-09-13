// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
//#define SIZE 5

//
// Array
//
template <typename T>
Array <T>::Array (void)
:       Array_Base <T>(),
        max_size_(SIZE)

{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:       Array_Base <T> (length),
        max_size_(SIZE)
{
    if(length == 0){
        max_size_ = SIZE;
    }
    else{
        max_size_ = length;
    }
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:       Array_Base <T> (length, fill), 
        max_size_(length)
{
    if(length == 0){
        max_size_ = SIZE;
    }
    else{
        max_size_ = length;
    }
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array <T> & array)
:       Array_Base <T>(array.size_), 
        max_size_(array.max_size_)
{
   
}

template <typename T>
Array <T>::~Array(void){
    //calls destructor of Array_Base
    
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    //check for self assignment
    if(this == &rhs){
        return *this;
    }

    this->size_ = rhs.size_;
    max_size_ = rhs.max_size_;

    delete[] this->ptr_;

    this->ptr_ = new T[max_size_];

    for(int i = 0; i < this->size(); i++){
        this->ptr_[i] = rhs.get(i);
    }
    return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //add padding to new_size
    //size_t length = new_size + this->max_size_;
    // save data to a new object of Array

    if(new_size > max_size_){
        
        T * arr = new T[new_size];

        for(size_t i = 0; i < this->size_; i++)
        {
            arr[i] = this->ptr_[i];
        }
        
        this->size_    = new_size;
        this->max_size_ = new_size;

        //swap pointers
        T * temp = arr;
        arr = this->ptr_;
        this->ptr_ = temp;

        delete [] arr;

    }
    
    else
    {
        this->size_ = new_size;
    }

}