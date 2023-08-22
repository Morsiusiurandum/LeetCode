//Given an integer columnNumber, return its corresponding column title as it 
//appears in an Excel sheet. 
//
// For example: 
//
// 
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28 
//...
// 
//
// 
// Example 1: 
//
// 
//Input: columnNumber = 1
//Output: "A"
// 
//
// Example 2: 
//
// 
//Input: columnNumber = 28
//Output: "AB"
// 
//
// Example 3: 
//
// 
//Input: columnNumber = 701
//Output: "ZY"
// 
//
// 
// Constraints: 
//
// 
// 1 <= columnNumber <= 2³¹ - 1 
// 
//
// Related Topics Math String 👍 4734 👎 656

#include <string>
#include <valarray>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static string convertToTitle(int columnNumber)
    {
        int n = columnNumber;
        string ans;
        while (n > 0)
        {
            n--;
            auto [q, r] = div(n, 26);
            ans.push_back(char('A' + r));
            n = q;
        }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};
//leetcode submit region end(Prohibit modification and deletion)
