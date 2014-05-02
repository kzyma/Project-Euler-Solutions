/*************************************************************
 *   File:   Problem6.cpp
 *   Author: Kenneth Zyma
 *   Date:   January, 2014
 *   This file is the solution to Problem 6 found on
 *       project Euler. http://projecteuler.net/
 *
 *   Problem: What is the 10,001th prime number?
 *
 *************************************************************/

#include<iostream>
#include<cmath>

bool isPrime(int);

int main(){
    int primeCounter = 0;
    int counter = 1;
    
    do {
        counter++;
        if(isPrime(counter)){
            primeCounter++;
        }
    }while (primeCounter < 10001);
    
    std::cout<<"10,001th prime number is: "<<counter<<std::endl;
    return 0;
}

/*returns true if parameter is prime, false otherwise*/
bool isPrime(const int n){
    int max = sqrt(n);
    for (int i=2; i<=max; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
