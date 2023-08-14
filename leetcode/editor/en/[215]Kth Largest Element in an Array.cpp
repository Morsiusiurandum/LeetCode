//Given an integer array nums and an integer k, return the kᵗʰ largest element 
//in the array. 
//
// Note that it is the kᵗʰ largest element in the sorted order, not the kᵗʰ 
//distinct element. 
//
// Can you solve it without sorting? 
//
// 
// Example 1: 
// Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
// 
// Example 2: 
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
// 
// Constraints: 
//
// 
// 1 <= k <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// Related Topics Array Divide and Conquer Sorting Heap (Priority Queue) Quick select 👍 15386 👎 725
#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<>> min_heap(nums.begin(), nums.begin() + k);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        return min_heap.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
