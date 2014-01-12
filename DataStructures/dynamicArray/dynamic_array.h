/***************************************************************
 *
 * file:    dynamic_array.h
 * author:  Ken Zyma
 * 
 * This file contains the header file for the templated dynamic
 * array class. This is implemented in typical fashion and
 * functions should behave expectedly.
 *
 * example usage:
 *  DynamicArray array;
 *  for(int i=0; i<3; i++){
 *      array[i]=i;
 *  }
 *  std::cout<<array[0]<<array[1]<<array[2}<<std::endl;
 *
 * output:
 * 012
 *
 * Modification history:
 *      created: January, 2014
 ***************************************************************/

#ifndef PROJECTEULER_DATASTRUCTURES_DYNAMICARRAY_DYNAMICARRAY_H
#define PROJECTEULER_DATASTRUCTURES_DYNAMICARRAY_DYNAMICARRAY_H

#include <iostream>

template<class T>
class DynamicArray{
private:
    std::size_t size;
    std::size_t capacity;
    T *array;
    
    void resize();
    
public:
    DynamicArray(const std::size_t capacity=10);
    DynamicArray(const DynamicArray<T>& original);
    DynamicArray<T> operator=(const DynamicArray<T>& rhs);
    ~DynamicArray();
    
    //capacity
    std::size_t getSize() const;
    std::size_t getCapacity() const;
    bool isEmpty() const;
    /*reduce capacity to size*/
    void shrinkToFit();
    
    //element access
    T const& operator[](size_t position) const;
    T front() const;
    T back() const;
    
    //modifiers
    void insert(T item);
    /*insert(T,size_t);
     *new element is inserted at index, and all elements at and after
     *index are shifted one back. This is relatively inefficient when 
     *compared with the same operation on other sequence containers */
    void insert(T item, std::size_t index);
    /*erase(size_t);
     *Erase the element at index and shrink size of container by 1.This is 
     * relatively inefficient when compared with the same operation
     * on other sequence containers */
    void erase(std::size_t index);
    void clear();
    
};
//nonmember functions

#include "dynamic_array.cxx"
#endif /*PROJECTEULER_DATASTRUCTURES/DYNAMICARRAY_DYNAMICARRAY_H*/
