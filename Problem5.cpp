/*************************************************************
 *   File:   Problem5.cpp
 *   Author: Kenneth Zyma
 *   Date:   January, 2014
 *   This file is the solution to Problem 5 found on
 *       project Euler. http://projecteuler.net/
 *
 *   Problem: What is the smallest positive number that is 
 *      evenly divisible by all of the numbers from 1 to 20?
 *
 *************************************************************/

#include<iostream>

bool isEvenlyDivisible(int,int);

int main(){
    int count = 21;
    
    for (int i=1; i<=20; i++) {
        if (!isEvenlyDivisible(i,count)) {
            count++;
            //restart loop counter
            i=1;
        }
    }
    std::cout<<"Lowest evenly divisible nubmer is :"<<count<<std::endl;
    return 0;
}

/* returns true if a divides b,
 * and false otherwise */
bool isEvenlyDivisible(const int a,const int b){
    if (b%a==0) {
        return true;
    }else{
        return false;
    }
}