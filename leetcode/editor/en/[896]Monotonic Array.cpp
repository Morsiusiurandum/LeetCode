//An array is monotonic if it is either monotone increasing or monotone
//decreasing.
//
// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j].
//An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
//
// Given an integer array nums, return true if the given array is monotonic, or
//false otherwise.
//
//
// Example 1:
//
//
//Input: nums = [1,2,2,3]
//Output: true
//
//
// Example 2:
//
//
//Input: nums = [6,5,4,4]
//Output: true
//
//
// Example 3:
//
//
//Input: nums = [1,3,2]
//Output: false
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 10⁵
// -10⁵ <= nums[i] <= 10⁵
//
//
// Related Topics Array 👍 2782 👎 82
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static bool isMonotonic(vector<int> &nums)
    {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                decreasing = false;
            }
            else if (nums[i] < nums[i - 1])
            {
                increasing = false;
            }
        }

        return increasing || decreasing;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
