/**
 * 
 * File: Problem1.java
 * @version: Problem1, Project Euler, V1.
 * @author: Ken Zyma
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * 
 * modifications:
 *      January 2014: file created
 */
package ProjectEuler;

/**
 * 
 */
public class Problem1 {
    public static void main(String[] args){
        int counter=0;
        
        for(int i=0;i<1000;i++){
            if(i%3==0) {
                counter+=i;
            }else if(i%5==0) {
                counter+=i;
            }else{
                //do nothing
            }
        }
        System.out.println("Answer: "+counter);
    }
}
