//Given a string containing digits from 2-9 inclusive, return all possible 
//letter combinations that the number could represent. Return the answer in any order. 
//
//
// A mapping of digits to letters (just like on the telephone buttons) is given 
//below. Note that 1 does not map to any letters. 
// 
// 
// Example 1: 
//
// 
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// Example 2: 
//
// 
//Input: digits = ""
//Output: []
// 
//
// Example 3: 
//
// 
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//
// 
// Constraints: 
//
// 
// 0 <= digits.length <= 4 
// digits[i] is a digit in the range ['2', '9']. 
// 
//
// Related Topics Hash Table String Backtracking 👍 16396 👎 875
#include<string>
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    const vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(const string &digits)
    {
        if (digits.empty()) return {};
        vector<string> output;
        backtrack(digits, output);
        return output;
    }

    void backtrack(string digits, vector<string> &output, const string &ans = "")
    {
        if (digits.empty())
        {
            output.push_back(ans);
            return;
        }

        int next_digits = (int) (digits[0] - '2');
        string letters = map[next_digits];
        string remains = digits.substr(1);
        for (char letter: letters)
        {
            backtrack(remains, output, ans + letter);
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
