//There is a strange printer with the following two special properties: 
//
// 
// The printer can only print a sequence of the same character each time. 
// At each turn, the printer can print new characters starting from and ending 
//at any place and will cover the original existing characters. 
// 
//
// Given a string s, return the minimum number of turns the printer needed to 
//print it. 
//
// 
// Example 1: 
//
// 
//Input: s = "aaabbb"
//Output: 2
//Explanation: Print "aaa" first and then print "bbb".
// 
//
// Example 2: 
//
// 
//Input: s = "aba"
//Output: 2
//Explanation: Print "aaa" first and then print "b" from the second place of 
//the string, which will cover the existing character 'a'.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 100 
// s consists of lowercase English letters. 
// 
//
// Related Topics String Dynamic Programming 👍 1634 👎 160
#include <vector>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = (int) s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                dp[i][j] = dp[i][j - 1] + 1;
                for (int k = i; k < j; ++k)
                {
                    // We don't need to care about the specific printing scheme of the interval [i,j - 1],
                    // because we can always complete the printing of s[i] in the first step.
                    // At this time, we can complete the printing of s[j] by the way,
                    // and it will not affect the printing completion of the interval [ i,j - 1] minimum number of operands.
                    if (s[k] == s[j])
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + (k + 1 <= j - 1 ? dp[k + 1][j - 1] : 0));
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
