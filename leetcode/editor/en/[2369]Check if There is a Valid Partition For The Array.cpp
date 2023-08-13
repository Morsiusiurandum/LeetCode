//You are given a 0-indexed integer array nums. You have to partition the array 
//into one or more contiguous subarrays. 
//
// We call a partition of the array valid if each of the obtained subarrays 
//satisfies one of the following conditions: 
//
// 
// The subarray consists of exactly 2 equal elements. For example, the subarray 
//[2,2] is good. 
// The subarray consists of exactly 3 equal elements. For example, the subarray 
//[4,4,4] is good. 
// The subarray consists of exactly 3 consecutive increasing elements, that is, 
//the difference between adjacent elements is 1. For example, the subarray [3,4,5]
// is good, but the subarray [1,3,5] is not. 
// 
//
// Return true if the array has at least one valid partition. Otherwise, return 
//false. 
//
// 
// Example 1: 
//
// 
//Input: nums = [4,4,4,5,6]
//Output: true
//Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6]
//.
//This partition is valid, so we return true.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,1,1,2]
//Output: false
//Explanation: There is no valid partition for this array.
// 
//
// 
// Constraints: 
//
// 
// 2 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁶ 
// 
//
// Related Topics Array Dynamic Programming 👍 1368 👎 160

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static bool validPartition(vector<int> &nums)
    {
        int n = (int) nums.size();
        if (n == 1) return false;

        vector<bool> dp = {true, false, n > 1 && nums[0] == nums[1]};

        for (int i = 2; i < n; i++)
        {
            bool current_dp
                    =
                    (nums[i] == nums[i - 1] && dp[1])
                    ||
                    (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[0])
                    ||
                    (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1 && dp[0]);

            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current_dp;
        }
        return dp[2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
