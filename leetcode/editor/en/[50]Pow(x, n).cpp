//Implement pow(x, n), which calculates x raised to the power n (i.e., xⁿ). 
//
// 
// Example 1: 
//
// 
//Input: x = 2.00000, n = 10
//Output: 1024.00000
// 
//
// Example 2: 
//
// 
//Input: x = 2.10000, n = 3
//Output: 9.26100
// 
//
// Example 3: 
//
// 
//Input: x = 2.00000, n = -2
//Output: 0.25000
//Explanation: 2⁻² = 1/2² = 1/4 = 0.25
// 
//
// 
// Constraints: 
//
// 
// -100.0 < x < 100.0 
// -2³¹ <= n <= 2³¹-1 
// n is an integer. 
// Either x is not zero or n > 0. 
// -10⁴ <= xⁿ <= 10⁴ 
// 
//
// Related Topics Math Recursion 👍 8129 👎 8086


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return x;
        }
        else if (n == -1)
        {
            return 1 / x;
        }
        double half = myPow(x, n / 2);
        double one = myPow(x, n % 2);
        return one * half * half;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
