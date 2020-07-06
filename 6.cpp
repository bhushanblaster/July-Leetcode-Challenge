/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        if(digits[digits.size()-1]<9)
        {
            digits[digits.size()-1]+=1;
        }
        else
        {
            int carry = 0;
            int i;
            for(i=digits.size()-1;i>=0;i--)
            {
                if(digits[i]==9)
                {
                    digits[i] = 0;
                    carry = 1;
                }
                else
                {
                    if(digits[i] == 9 && carry)
                    {
                        digits[i] = 0;
                        carry = 1;
                    }
                    else
                    {
                        digits[i] += carry;
                        carry = 0;
                        break;
                    }
                }
            }
            if(i<0 && carry)
            {
                reverse(digits.begin(),digits.end());
                digits.push_back(1);
                reverse(digits.begin(),digits.end());
            }
            return digits;
            
        }
        
        return digits;
        
    }
};
