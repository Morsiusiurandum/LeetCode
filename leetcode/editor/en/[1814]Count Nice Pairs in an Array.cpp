//You are given an array nums that consists of non-negative integers. Let us
//define rev(x) as the reverse of the non-negative integer x. For example, rev(123) =
// 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all
//of the following conditions:
//
//
// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
//
//
// Return the number of nice pairs of indices. Since that number can be too
//large, return it modulo 10⁹ + 7.
//
//
// Example 1:
//
//
//Input: nums = [42,11,1,97]
//Output: 2
//Explanation: The two pairs are:
// - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
// - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
//
//
// Example 2:
//
//
//Input: nums = [13,10,35,24,76]
//Output: 4
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 10⁵
// 0 <= nums[i] <= 10⁹
//
//
// Related Topics Array Hash Table Math Counting 👍 1441 👎 63
#include <algorithm>
#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int reverse(int num)
    {
        int rev = 0;
        while (num > 0)
        {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    [[maybe_unused]] static int countNicePairs(std::vector<int> &nums)
    {
        const int mod = 1000000007;

        int len = (int) nums.size();

        //Change the array
        for (int i = 0; i < len; ++i)
        {
            nums[i] = nums[i] - reverse(nums[i]);
        }

        std::sort(nums.begin(), nums.end());

        //Collection the answer
        long res = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            long cont = 1;
            while (i < len - 1 && nums[i] == nums[i + 1])
            {
                cont++;
                i++;
            }
            res += (cont * (cont - 1)) / 2;
        }

        return static_cast<int>(res % mod);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
