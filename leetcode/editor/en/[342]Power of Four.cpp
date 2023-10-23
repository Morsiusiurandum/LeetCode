//Given an integer n, return true if it is a power of four. Otherwise, return
//false.
//
// An integer n is a power of four, if there exists an integer x such that n ==
//4ˣ.
//
//
// Example 1:
// Input: n = 16
//Output: true
//
// Example 2:
// Input: n = 5
//Output: false
//
// Example 3:
// Input: n = 1
//Output: true
//
//
// Constraints:
//
//
// -2³¹ <= n <= 2³¹ - 1
//
//
//
//Follow up: Could you solve it without loops/recursion?
//
// Related Topics Math Bit Manipulation Recursion 👍 3605 👎 364
#include <cmath>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static bool isPowerOfFour(int n)
    {
        if (n == 0) return false;
        double math = (log(n) / log(4));
        return math == floor(math);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
