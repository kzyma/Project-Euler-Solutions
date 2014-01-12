/*************************************************************
 *   File:   Problem10.cpp
 *   Author: Ken Zyma
 *   Date:   January, 2014
 *   This file is the solution to Problem 10 found on
 *       project Euler. http://projecteuler.net/
 *
 *   Problem: Find the sum of all the primes below two million.
 *
 *************************************************************/

#include<iostream>
#include <math.h>

#include "DataStructures/dynamicArray/dynamic_array.h"

bool isPrime(long);

int main(){
    //init with sum of all even primes
    long sum=17;
    long max=2000000;
    
    for (long i= 9; i<max; i=i+2) {
        if (isPrime(i)) {
            sum+=i;
        }
    }
    
    std::cout<<"Sum: "<<sum<<std::endl;
    return 0;
}

bool isPrime(long number){
    for (long i=2; i<=sqrt(number); i++) {
        if (number%i==0) {
            return false;
        }
    }
    return true;
}