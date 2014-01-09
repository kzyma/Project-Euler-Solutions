/*************************************************************
 *   File:   Problem9.cpp
 *   Author: Kenneth Zyma
 *   Date:   January, 2014
 *   This file is the solution to Problem 9 found on
 *       project Euler. http://projecteuler.net/
 *
 *   Problem:There exists exactly one Pythagorean triplet for 
 *           which a + b + c 1000. Find the product abc.
 *
 *************************************************************/

#include<iostream>

int main(){
    int a;
    int b;
    int c;
    int sum;
    
    /*max was found with the following assumption:
     *         c<1000
     *   n^2+m^2<1000
     *   when m=1, n is approx. 32 */
    int max = 32;
    
    for (int m=1; m<=max; m++) {
        for (int n=m+1; n<=max; n++) {
            a=(n*n)-(m*m);
            b=(2*n*m);
            c=(n*n)+(m*m);
            if (a+b+c==1000) {
                std::cout<<"Product of (abc): "<<(a*b*c)<<std::endl;
            }
        }
    }
    return 0;
}