/**
Write a function to find the longest common prefix string amongst an array of 
strings. 

 If there is no common prefix, return an empty string "". 

 
 Example 1: 

 
Input: strs = ["flower","flow","flight"]
Output: "fl"
 

 Example 2: 

 
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

 
 Constraints: 

 
 1 <= strs.length <= 200 
 0 <= strs[i].length <= 200 
 strs[i] consists of only lowercase English letters. 
 

 Related Topics String 👍 11952 👎 3621

*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans;
        for (int i = 0; i < 200; ++i)
        {
            char curr = strs[0][i];
            for (auto &str: strs)
            {
                if (i >= str.length()) return ans;
                if (str[i] != curr) return ans;
            }
            ans += curr;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
