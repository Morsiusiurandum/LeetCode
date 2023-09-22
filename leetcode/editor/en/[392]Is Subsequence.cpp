//Given two strings s and t, return true if s is a subsequence of t, or false
//otherwise.
//
// A subsequence of a string is a new string that is formed from the original
//string by deleting some (can be none) of the characters without disturbing the
//relative positions of the remaining characters. (i.e., "ace" is a subsequence of
//"abcde" while "aec" is not).
//
//
// Example 1:
// Input: s = "abc", t = "ahbgdc"
//Output: true
//
// Example 2:
// Input: s = "axc", t = "ahbgdc"
//Output: false
//
//
// Constraints:
//
//
// 0 <= s.length <= 100
// 0 <= t.length <= 10⁴
// s and t consist only of lowercase English letters.
//
//
//
//Follow up: Suppose there are lots of incoming
//s, say
//s1, s2, ..., sk where
//k >= 10⁹, and you want to check one by one to see if
//t has its subsequence. In this scenario, how would you change your code?
//
// Related Topics Two Pointers String Dynamic Programming 👍 8716 👎 467
#include <string>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int isSubs(string &s1, string &s2, int i, int j, vector<vector<int>> &t)
    {
        if (i == 0 || j == 0) return 0;

        if (t[i][j] != -1) return t[i][j];
        
        if (s1[i - 1] == s2[j - 1])
        {
            return t[i][j] = 1 + isSubs(s1, s2, i - 1, j - 1, t);
        }
        else
        {
            return t[i][j] = isSubs(s1, s2, i, j - 1, t);
        }
    }

    bool isSubsequence(string s1, string s2)
    {
        int m = (int) s1.length();
        int n = (int) s2.length();


        if (m > n) return false;

        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

        return (isSubs(s1, s2, m, n, t) == m);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
