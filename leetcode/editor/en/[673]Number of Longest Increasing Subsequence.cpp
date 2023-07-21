//Given an integer array nums, return the number of longest increasing 
//subsequences. 
//
// Notice that the sequence has to be strictly increasing. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,5,4,7]
//Output: 2
//Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 
//3, 5, 7].
// 
//
// Example 2: 
//
// 
//Input: nums = [2,2,2,2,2]
//Output: 5
//Explanation: The length of the longest increasing subsequence is 1, and there 
//are 5 increasing subsequences of length 1, so output 5.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 2000 
// -10⁶ <= nums[i] <= 10⁶ 
// 
//
// Related Topics Array Dynamic Programming Binary Indexed Tree Segment Tree 👍 
//5867 👎 238

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = (int) nums.size(), res = 0, max_len = 0;
        //dp[i]: {length, number of LIS which ends with nums[i]}
        vector<pair<int, int>> dp(n, {1, 1});
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                    if (dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if (max_len == dp[i].first)res += dp[i].second;
            if (max_len < dp[i].first)
            {
                max_len = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
