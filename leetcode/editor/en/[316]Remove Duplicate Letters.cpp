//Given a string s, remove duplicate letters so that every letter appears once
//and only once. You must make sure your result is the smallest in lexicographical
//order among all possible results.
//
//
// Example 1:
//
//
//Input: s = "bcabc"
//Output: "abc"
//
//
// Example 2:
//
//
//Input: s = "cbacdcbc"
//Output: "acdb"
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
//
// Note: This question is the same as 1081: https://leetcode.com/problems/
//smallest-subsequence-of-distinct-characters/
//
// Related Topics String Stack Greedy Monotonic Stack 👍 7898 👎 518
#include <stack>
#include <string>
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static string removeDuplicateLetters(string s)
    {
        vector<int> last_occurrence(26, -1);
        vector<bool> used(26, false);
        stack<char> st;

        // Calculate the last occurrence of each character in the string
        for (int i = 0; i < s.size(); ++i)
        {
            last_occurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            char currChar = s[i];

            if (!used[currChar - 'a'])
            {
                while (!st.empty() && currChar < st.top() && last_occurrence[st.top() - 'a'] > i) {
                    used[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(currChar);
                used[currChar - 'a'] = true;
            }
        }

        string result(st.size(), ' ');

        // Construct the result string in reverse order from the stack
        for (int i = (int) st.size() - 1; i >= 0; --i)
        {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
