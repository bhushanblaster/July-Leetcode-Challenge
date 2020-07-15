/*

Solution
Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

class Solution {
public:
    string reverseWords(string s) {
       
        string ans;
        int end = s.size()-1;
        bool wordStarted = false;
        while (end >= 0)
        {
            while (end >= 0 && !wordStarted && s[end] == ' ')
                end--;
            if (end<0)
                break;
            wordStarted = true;
            string curr = "";
            while (  end >= 0 &&  s[end] != ' ')
            {
                curr = s[end] + curr;
                end--;
            }
            ans += curr + ' ';
            wordStarted = false;
        }
        return ans.substr(0,ans.size()-1);
    }
};
