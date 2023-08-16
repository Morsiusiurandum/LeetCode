//You are given an array of integers nums, there is a sliding window of size k 
//which is moving from the very left of the array to the very right. You can only 
//see the k numbers in the window. Each time the sliding window moves right by one 
//position. 
//
// Return the max sliding window. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// Example 2: 
//
// 
//Input: nums = [1], k = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics Array Queue Sliding Window Heap (Priority Queue) Monotonic 
//Queue 👍 16242 👎 547
#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = (int) nums.size();
        deque<int> max_idx;//Double-ended queue storing index for max
        vector<int> ans(n - k + 1);

        for (int i = 0; i < n; i++)
        {
            while (!max_idx.empty() && nums[i] >= nums[max_idx.back()])
                max_idx.pop_back();// pop back the indexes for smaller ones
            max_idx.push_back(i);  // push back the index for larger one

            if (max_idx.front() == i - k) // index=i-k should not in the window
                max_idx.pop_front();
            if (i >= k - 1)
                ans[i - k + 1] = nums[max_idx.front()]; //Max element for this window
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
