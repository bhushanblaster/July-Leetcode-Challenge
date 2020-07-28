/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
             
*/

class Solution {
public:
    int addDigits(int num) {
        
        while(num/10)
        {
            int num1 = num,sum = 0;
            while(num1)
            {
                sum += num1%10;
                num1=num1/10;
            }
            num = sum;
        }
        
        return num;
    }
};
