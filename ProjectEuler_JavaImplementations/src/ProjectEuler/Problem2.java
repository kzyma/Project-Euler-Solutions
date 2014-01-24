/**
 * 
 * File: Problem2.java
 * @version: Problem2, Project Euler, V1.
 * @author: Ken Zyma
 * 
 * By considering the terms in the Fibonacci sequence 
 * whose values do not exceed four million, find the sum 
 * of the even-valued terms.
 * 
 * modifications:
 *      January 2014: file created
 */
package ProjectEuler;

public class Problem2 {
    public static void main(String[] args){
        int a=1;
        int b=2;
        int c;
        long sum=2; //includes the initial fib. sequence values (2)
        boolean limitReached=false;
        while(!limitReached){
            c=a+b;
            a=b;
            b=c;
            if(c%2==0){
                sum+=c;
            }
            if(c>=4000000){
                limitReached=true;
            }
        }
        //print result
        System.out.println("Sum is: "+sum);
    }
}
