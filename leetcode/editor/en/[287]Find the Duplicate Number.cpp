//Given an array of integers nums containing n + 1 integers where each integer
//is in the range [1, n] inclusive.
//
// There is only one repeated number in nums, return this repeated number.
//
// You must solve the problem without modifying the array nums and uses only
//constant extra space.
//
//
// Example 1:
//
//
//Input: nums = [1,3,4,2,2]
//Output: 2
//
//
// Example 2:
//
//
//Input: nums = [3,1,3,4,2]
//Output: 3
//
//
//
// Constraints:
//
//
// 1 <= n <= 10⁵
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer
//which appears two or more times.
//
//
//
// Follow up:
//
//
// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity?
//
//
// Related Topics Array Two Pointers Binary Search Bit Manipulation 👍 21276 👎
//3540
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static int findDuplicate(vector<int> &nums)
    {
        int len = (int) nums.size();
        for (int i = 0; i < len;)
        {
            int n = nums[i];
            if (n == i + 1)
            {
                i++;
            }
            else if (n == nums[n - 1])
            {
                return n;
            }
            else
            {
                nums[i] = nums[n - 1];
                nums[n - 1] = n;
            }
        }

        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
