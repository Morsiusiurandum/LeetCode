//Given a string s, check if it can be constructed by taking a substring of it 
//and appending multiple copies of the substring together. 
//
// 
// Example 1: 
//
// 
//Input: s = "abab"
//Output: true
//Explanation: It is the substring "ab" twice.
// 
//
// Example 2: 
//
// 
//Input: s = "aba"
//Output: false
// 
//
// Example 3: 
//
// 
//Input: s = "abcabcabcabc"
//Output: true
//Explanation: It is the substring "abc" four times or the substring "abcabc" 
//twice.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of lowercase English letters. 
// 
//
// Related Topics String String Matching 👍 5491 👎 452
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static bool repeatedSubstringPattern(const string &s)
    {
        int n = (int) s.size();
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                if (s.substr(0, n - i) == s.substr(i))
                    return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
