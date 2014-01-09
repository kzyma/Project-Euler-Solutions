/********************************************************
*   File:   Problem3.cpp
*   Author: Kenneth Zyma
*   Date:   January, 2014
*   This file is the solution to Problem 3 found on
*       project Euler. http://projecteuler.net/
*
*   Problem: What is the largest prime factor of 
*               the number 600851475143?
*********************************************************/
#include<iostream>
#include <math.h> 

long findLargestPrimeFactor(long);

int main(){
    long largestFactor=0;
    largestFactor = findLargestPrimeFactor(600851475143);
    std::cout<<"Largest Prime Factor is: "<<largestFactor<<std::endl;
    return 0;
}

long findLargestPrimeFactor(long number){
    for (long count=2; count<(number/2); count++) {
        if((number%count)==0){
            number /= count;
            //reset counter
            count=2;
        }
    }
    return number;
}