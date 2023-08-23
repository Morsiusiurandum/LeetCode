//Given a string s, rearrange the characters of s so that any two adjacent 
//characters are not the same. 
//
// Return any possible rearrangement of s or return "" if not possible. 
//
// 
// Example 1: 
// Input: s = "aab"
//Output: "aba"
// 
// Example 2: 
// Input: s = "aaab"
//Output: ""
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 500 
// s consists of lowercase English letters. 
// 
//
// Related Topics Hash Table String Greedy Sorting Heap (Priority Queue) 
//Counting 👍 7402 👎 221
#include <string>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static string reorganizeString(string s)
    {
        int n = (int) s.length();

        unordered_map<int, int> mp;
        for (auto it: s) mp[it]++;

        int maxFreq = 0;
        char maxChar;
        for (auto it: mp)
        {
            if (maxFreq < it.second)
            {
                maxChar = (char) it.first;
                maxFreq = it.second;
            }
        }

        int ind;
        for (ind = 0; ind < n; ind += 2)
        {
            s[ind] = maxChar;
            maxFreq--;
            if (!maxFreq)
            {
                mp.erase(maxChar);
                break;
            }
        }

        if (maxFreq) return "";

        for (auto it: mp)
        {
            char currChar = (char) it.first;
            int currFreq = it.second;
            while (currFreq)
            {
                ind = ind + 2 >= n ? 1 : ind + 2;
                s[ind] = currChar;
                currFreq--;
            }
        }

        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
