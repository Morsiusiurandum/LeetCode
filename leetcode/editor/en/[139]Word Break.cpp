//Given a string s and a dictionary of strings wordDict, return true if s can 
//be segmented into a space-separated sequence of one or more dictionary words. 
//
// Note that the same word in the dictionary may be reused multiple times in 
//the segmentation. 
//
// 
// Example 1: 
//
// 
//Input: s = "leetcode", wordDict = ["leet","code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
// 
//
// Example 2: 
//
// 
//Input: s = "applepenapple", wordDict = ["apple","pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple 
//pen apple".
//Note that you are allowed to reuse a dictionary word.
// 
//
// Example 3: 
//
// 
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s and wordDict[i] consist of only lowercase English letters. 
// All the strings of wordDict are unique. 
// 
//
// Related Topics Array Hash Table String Dynamic Programming Trie Memoization ?
//? 15439 👎 646

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool wordBreak(const string &s, vector<string> &wordDict)
    {
        int n = (int) s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        int sub_string_max_length = 0;
        for (const auto &word: wordDict)
        {
            sub_string_max_length = max(sub_string_max_length, static_cast<int>(word.size()));
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= max(i - sub_string_max_length - 1, 0); j--)
            {
                bool has_find =
                        find(wordDict.begin(), wordDict.end(), s.substr(j, i - j))
                        != wordDict.end();

                if (dp[j] && has_find)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

};
//leetcode submit region end(Prohibit modification and deletion)
