/********************************************************
 *   File:   Problem4.cpp
 *   Author: Kenneth Zyma
 *   Date:   January, 2014
 *   This file is the solution to Problem 4 found on
 *       project Euler. http://projecteuler.net/
 *
 *   Problem: Find the largest palindrome made from 
 *            the product of two 3-digit numbers.
 *********************************************************/

#include<iostream>
#include <string>

bool isPalindrome(int);
long findLargestPalindrome(int,int);

int main(){
    int max = 999;
    int currentLargestPalindrome=0;
    
    for (int i=0; i<=max; i++) {
        for (int j=0; j<=max; j++) {
            if ((isPalindrome(i*j))&&((i*j)>currentLargestPalindrome)){
                currentLargestPalindrome = (i*j);
            }
        }
    }
    std::cout<<"Largest palindrome made from the product of two ";
    std::cout<<"three digit numbers is: "<<currentLargestPalindrome;
    std::cout<<std::endl;
    return 0;
}

/*function returns true if integer passed is a palindrome, false
 * otherwise */
bool isPalindrome(int palindromicNumber){
    
    std::string originalStr = std::to_string(palindromicNumber);
    std::size_t size = originalStr.length();
    std::size_t halfSize = (size/2);
    
    for (int i=0; i<halfSize; i++) {
        if(originalStr[i]!=originalStr[(size-1)-i]){
            return false;
        }
    }
    return true;
}