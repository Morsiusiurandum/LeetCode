//You are given a 0-indexed string s and a dictionary of words dictionary. You 
//have to break s into one or more non-overlapping substrings such that each 
//substring is present in dictionary. There may be some extra characters in s which are 
//not present in any of the substrings. 
//
// Return the minimum number of extra characters left over if you break up s 
//optimally. 
//
// 
// Example 1: 
//
// 
//Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
//Output: 1
//Explanation: We can break s in two substrings: "leet" from index 0 to 3 and 
//"code" from index 5 to 8. There is only 1 unused character (at index 4), so we 
//return 1.
//
// 
//
// Example 2: 
//
// 
//Input: s = "sayhelloworld", dictionary = ["hello","world"]
//Output: 3
//Explanation: We can break s in two substrings: "hello" from index 3 to 7 and 
//"world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in 
//any substring and thus are considered as extra characters. Hence, we return 3.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 50 
// 1 <= dictionary.length <= 50 
// 1 <= dictionary[i].length <= 50 
// dictionary[i] and s consists of only lowercase English letters 
// dictionary contains distinct words 
// 
//
// Related Topics Array Hash Table String Dynamic Programming Trie 👍 1364 👎 65
//

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int minExtraChar(const string &s, vector<string> &dictionary)
    {
        int max_val = (int) s.length() + 1;
        vector<int> dp(s.length() + 1, max_val);
        dp[0] = 0;

        unordered_set<string> dictionary_set(dictionary.begin(), dictionary.end());

        for (int i = 1; i <= s.length(); ++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int l = 1; l <= i; ++l)
            {
                if (dictionary_set.find(s.substr(i - l, l)) != dictionary_set.end())
                {
                    dp[i] = min(dp[i], dp[i - l]);
                }
            }
        }
        return dp.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
