//Given an integer n, break it into the sum of k positive integers, where k >= 2
//, and maximize the product of those integers.
//
// Return the maximum product you can get.
//
//
// Example 1:
//
//
//Input: n = 2
//Output: 1
//Explanation: 2 = 1 + 1, 1 × 1 = 1.
//
//
// Example 2:
//
//
//Input: n = 10
//Output: 36
//Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
//
//
//
// Constraints:
//
//
// 2 <= n <= 58
//
//
// Related Topics Math Dynamic Programming 👍 4124 👎 385
#include <cmath>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static int integerBreak(int n)
    {
        if (n <= 3) return n - 1;
        int quotient = n / 3, remainder = n % 3;
        if (remainder == 0) return (int) pow(3, quotient);
        if (remainder == 1) return (int) pow(3, quotient - 1) * 4;
        return (int) pow(3, quotient) * 2;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
