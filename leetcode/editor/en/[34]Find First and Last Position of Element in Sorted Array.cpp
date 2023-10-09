//Given an array of integers nums sorted in non-decreasing order, find the
//starting and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// You must write an algorithm with O(log n) runtime complexity.
//
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//
// Example 3:
// Input: nums = [], target = 0
//Output: [-1,-1]
//
//
// Constraints:
//
//
// 0 <= nums.length <= 10⁵
// -10⁹ <= nums[i] <= 10⁹
// nums is a non-decreasing array.
// -10⁹ <= target <= 10⁹
//
//
// Related Topics Array Binary Search 👍 19066 👎 459
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        if (left <= right) {
            return {left, right};
        }
        else {
            return {-1, -1};
        }
    }

private:
    static int binarySearch(vector<int> &nums, int target, bool findLeft)
    {
        int low = 0;
        int high = (int) nums.size() - 1;
        int index = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                index = mid;
                if (findLeft) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return index;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
