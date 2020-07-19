/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans="";
        
        int ai =a.size()-1,bi=b.size()-1;
        while(ai >= 0 && bi >= 0)
        {
            int x=0,y=0;
            
            if(a[ai]=='1')
                x = 1;
            if(b[bi]=='1')
                y = 1;
            
            if(x+y+carry == 0)
            {
                ans = '0'+ans;
                carry = 0;
            }
            else if(x+y+carry == 1)
            {
                ans = '1'+ ans;
                carry = 0;
            }
            else if(x+y+carry == 2)
            {
                ans = '0'+ ans;
                carry = 1;
            }
            else
            {
                ans = '1' + ans;
                carry = 1;
            }
            ai--;
            bi--;
        }
        while(ai >= 0)
        {
            if(carry)
            {
                if(a[ai]=='1')
                {
                   ans = '0' + ans;
                   carry = 1;
                }
                else
                {
                    ans = '1' +ans;
                    carry = 0;
                }
            }
            else
            {
                ans = a[ai]+ans;
            }
            ai--;
        }
        while(bi>=0)
        {
            if(carry)
            {
                if(b[bi]=='1')
                {
                   ans = '0' + ans;
                   carry = 1;
                }
                else
                {
                    ans = '1' +ans;
                    carry = 0;
                }
            }
            else
            {
                ans = b[bi]+ans;
            }
            bi--;
        }
        if(carry)
            ans = '1'+ans;
        
        return ans;
    }
};
