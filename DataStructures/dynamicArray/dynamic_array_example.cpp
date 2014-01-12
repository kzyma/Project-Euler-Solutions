/***************************************************************
 *
 * file:    dynamic_array_example.cxx
 * author:  Ken Zyma
 *
 * This file contains an example for the Dynamic Array class.
 * This does not serve as a unit test for the class and instead
 * is intended to show how the class can work.
 *
 * Modification history:
 *      created: January, 2014
 ***************************************************************/

#include "dynamic_array.h"

void printArray(const DynamicArray<int>&);

int main(){
    DynamicArray<int> array;
    
    std::cout<<"Is the array empty? Yes(1) "<<array.isEmpty()<<std::endl;
    
    //insert consecutive integers 0,1,...6 into array using insert
    for (int i=0; i<7; i++) {
        array.insert(i);
    }
    std::cout<<"Values 0-6 inserted into array:"<<std::endl;
    printArray(array);
    std::cout<<"Now is the array empty? No(0) "<<array.isEmpty()<<std::endl;
    
    
    //copy constructor
    std::cout<<"contents of arrayB after copy constructor is invoked: "<<std::endl;
    DynamicArray<int> arrayB(array);
    printArray(arrayB);
    arrayB.clear();
    std::cout<<"contents of arrayB after clear: "<<std::endl;
    printArray(arrayB);
    
    //add integers to arrayB
    for (int i=4; i>=0; i--) {
        arrayB.insert(i);
    }
    std::cout<<"ArrayB contents after adding elements: "<<std::endl;
    printArray(arrayB);
    //and prove this did not effect the original array
    std::cout<<"Original Array contents: "<<std::endl;
    printArray(array);
    
    // (=) operator
    array=arrayB;
    std::cout<<"array contents after array=arrayB;: "<<std::endl;
    printArray(array);
    
    array.insert(20);
    std::cout<<"insert int 20 into array, the contents of array is now: "<<std::endl;
    printArray(array);
    std::cout<<"the contents arrayB is: "<<std::endl;
    printArray(arrayB);
    
    //element access
    std::cout<<"front array member: "<<array.front()<<" back array member: ";
    std::cout<<array.back()<<std::endl;
    
    std::cout<<"array contents pre-insert: "<<std::endl;
    printArray(array);
    array.insert(9,2);
    std::cout<<"array contents after inserting 9 at index 2: "<<std::endl;
    printArray(array);
    
    array.erase(3);
    std::cout<<"array contents after erasing index 3: "<<std::endl;
    printArray(array);
    
    std::cout<<"Size of container before shrinkToFit: "<<std::endl;
    std::cout<<array.getCapacity()<<std::endl;
    std::cout<<"Size of container after shrinkToFit: "<<std::endl;
    array.shrinkToFit();
    std::cout<<array.getCapacity()<<std::endl;
    
    return 0;
}

/*print the contents of an array usign " " to delimit*/
void printArray(const DynamicArray<int>& array){
    for (int i=0; i<array.getSize(); i++) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}
