#include "Array_Base.h"
#include <stdexcept>
#include <iostream>

#define SIZE 10

//default constructor
template <typename T>
Array_Base <T>::Array_Base (void)
:   ptr_(0),    
    size_(SIZE)    
{
    this->ptr_ = new T[SIZE];
}

//Initializing constructor
template <typename T>
Array_Base <T>::Array_Base (size_t length)
:   ptr_(0),
    size_(length)
{
    if(length == 0){
        ptr_ = new T[SIZE];
    }
    else{
        ptr_ = new T[length];
    }

}

//Initializing constructor
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
:   ptr_(0),
    size_(length)
{
    if(length == 0){
        ptr_ = new T[SIZE];
    }
    else{
        ptr_ = new T[length];
    }
    this->fill(fill);
}

//copy constructor
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & arr)
:   ptr_(0),
    size_(arr.size_)
{
    if(arr.size_ != this->size_){           // check if sizes are not same then throw an error
        throw "Sizes are not same";
    }
    
    ptr_ = new T[SIZE];                     
    
    // copy elements of original array to the new array
    for(size_t i = 0; i < arr.size(); i++){
        ptr_[i] = arr.ptr_[i];
    }
}

//destructor
template <typename T>
Array_Base <T>::~Array_Base(void)
{
    delete [] ptr_;
    ptr_ = 0;
}

// assignment = operator
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base <T> &rhs)
{
    //check for self assignment
    if(this == &rhs){
        return *this;
    }
    if(this->size() != rhs.size())
    {
        std::cout << "Size of rhs is not same as of lhs" << std::endl;
    }

    for(int i = 0; i < size(); i++)
    {
        this->ptr_[i] = rhs[i];
    }
    return *this;

}

//get method
template <typename T>
T Array_Base <T>::get(size_t index) const
{
    if(index >= size_ || index < 0){
        throw std::out_of_range("Array index out of range");
    }
    return ptr_[index];
}

//set method
template <typename T>
void Array_Base <T>::set (size_t index, T element)
{
    if(index >= size_ || index < 0){
        throw std::out_of_range("Index out of range");
     }
    ptr_[index] = element;
}

// []
template <typename T>
T & Array_Base<T> :: operator[] (size_t index)
{
    if(index >= size_ || index < 0){
        throw std::out_of_range("Array index out of range");
    }
    return ptr_[index];
}

// [] const
template <typename T>
const T & Array_Base<T> :: operator[] (size_t index) const
{
    if(index >= size_ || index < 0){
        throw std::out_of_range("Array index out of range");
    }
    return ptr_[index];
}

// find (element)
template  <typename T>
int Array_Base <T>::find (T element) const
{
    try{
        return find(element, 0);
    }
    catch(const std::out_of_range &){

    }
    return -1;
}

// find ( element, size_t t)
template <typename T>
int Array_Base <T>::find (T element, size_t start) const
{
    if(start >= size_){
        throw std::out_of_range("Array index out of range");
    }
    if(start < this->size_){
        for(size_t i = start; i < this->size_; i++){
            if(this->ptr_[i] == element){
                return i;
            }
        }
    }
    return -1;
}

// ==
template <typename T>
bool Array_Base<T> ::operator == (const Array_Base & rhs) const
{
    //check for self assignment
    if(this == &rhs){
        return true;
    }
    if(this->size_ != rhs.size_){
        return false;
    }
    if(this->size_ == rhs.size_){
        for(size_t i = 0; i < this->size_; i++){
            if(this->ptr_[i] != rhs.ptr_[i]){
                return false;
            }
        }
    }
    return true;

}

// !=
template <typename T>
bool Array_Base<T> ::operator!= (const Array_Base & rhs) const
{
    //check for self assignment
    if(this == &rhs){
        return false;
    }
    // if size don't match then return false
    if(this->size_ != rhs.size_){
        return true;
    }

    if(this->size_ == rhs.size_){
        for(int i = 0; i < this->size_; i++){
            if(this->ptr_[i] != rhs.ptr_[i]){
                return true;
            }
        }
    }
    return false;
}

//fill
template <typename T>
void Array_Base <T>::fill (T value)
{
    for(size_t i = 0; i < size_;i++)
    {
        ptr_[i] = value;
    }
}