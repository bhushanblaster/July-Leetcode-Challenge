/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
       
        vector<int>uglies(n);
        uglies[0]=1;
        int u2 =0, u3 = 0,u5 = 0;
        for(int i=1;i<n;i++)
        {
            int ugly = min(2*uglies[u2],min(3*uglies[u3],5*uglies[u5]));
            uglies[i] = ugly;
            if(uglies[i]==2*uglies[u2])
                u2++;
            if(3*uglies[u3]==uglies[i])
                u3++;
            if(5*uglies[u5] == uglies[i])
                u5++;
            cout<<uglies[i]<<" ";
        }
        return uglies[n-1];
    }
};
