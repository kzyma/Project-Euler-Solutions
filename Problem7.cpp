/*************************************************************
 *   File:   Problem7.cpp
 *   Author: Kenneth Zyma
 *   Date:   January, 2014
 *   This file is the solution to Problem 7 found on
 *       project Euler. http://projecteuler.net/
 *
 *   Problem: Find the greatest product of five consecutive 
 *              digits in the 1000-digit number...
 *
 *************************************************************/

#include<iostream>
#include <fstream>
#include <string>

/********************************************************************/
/* Queue data structure from circular array of size 5, FIFO,
 * note: operations are only really relevent for this problem,
 * for a circular array with typical implementation and oper.
 * look in the data structures folder. */
class FixedSizeQueue{
private:
    int intBuffer[5];
    int index;
public:
    FixedSizeQueue(){
        index=0;
        for (int i=0; i<5; i++) {
            intBuffer[i]=0;
        }
    }
    void insert(int a){
        //reset size to overright first element
        if (index>=5) {
            index=0;
        }
        intBuffer[index]=a;
        index++;
    }
    int product(){
        int product=1;
        for (int i=0; i<5; i++) {
            product*=intBuffer[i];
        }
        return product;
    }
    friend std::ostream& operator<<(std::ostream&, const FixedSizeQueue&);
    friend std::istream& operator>>(std::istream&, FixedSizeQueue&);
    FixedSizeQueue& operator=(const FixedSizeQueue&);
};
//nonmember functions
std::ostream& operator<<(std::ostream& os, const FixedSizeQueue& q){
    for (int i=0; i < 5; i++) {
        os<<std::dec<<q.intBuffer[i];
    }
    return os;
}
std::istream& operator>>(std::istream& is,FixedSizeQueue& q){
    is>>q.intBuffer[q.index];
    return is;
}
FixedSizeQueue& FixedSizeQueue::operator= (const FixedSizeQueue& q){
    for (int i=0; i<5; i++) {
        intBuffer[i] = q.intBuffer[i];
    }
    return *this;
}
/***********************************************************************/

int main(){
    FixedSizeQueue currentBuffer;
    int currentHigh;
    char dummyChar;
    std::ifstream dataFile;
    
    //open file
    dataFile.open("data/problem7Data.txt");
    if(dataFile.is_open()){
        //get first summation of 5 numbers
        for (int i=0; i<5; i++) {
            dataFile>>dummyChar;
            //convert char to integer value
            currentBuffer.insert((dummyChar - '0') % 48);
        }
        currentHigh=currentBuffer.product();
        
        /*continue adding 1 number, and checking summation against
        * current high until end of file*/
        while (!(dataFile.eof())) {
            dataFile>>dummyChar;
            currentBuffer.insert((dummyChar - '0') % 48);
            if ((currentBuffer.product()) > (currentHigh)) {
                currentHigh=currentBuffer.product();
            }
        }
        dataFile.close();
    }else{
        std::cout<<"Error opening file: data/problem7Data.txt \n";
    }
    
    //output highest 5 numbers
    std::cout<<"Largest 5 digits sum to: "<<currentHigh<<std::endl;
    return 0;
}
