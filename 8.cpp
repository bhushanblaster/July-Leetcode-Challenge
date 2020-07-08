/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        int n = nums.size();
        
        if(n<3)
            return ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        for(int i=0;i<nums.size()-2;i++)
        {
            int curr = nums[i];
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                int sum = curr+nums[left]+nums[right];
                if(sum==0)
                {
                    /*vector<int>temp(3);
                    temp[0]=curr;
                    temp[1]=nums[left];
                    temp[2]=nums[right];
                    sort(temp.begin(),temp.end());
                    if(find(ans.begin(),ans.end(),temp) == ans.end())
                          ans.push_back(temp);
                    left++;right--;*/
                    
                    s.insert({curr,nums[left],nums[right]});
                    left++;right--;
                }
                else if(sum<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        for(auto s1:s)
            ans.push_back(s1);
       return ans;
        
    }
};
