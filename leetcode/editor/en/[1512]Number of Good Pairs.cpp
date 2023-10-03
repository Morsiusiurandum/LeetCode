//Given an array of integers nums, return the number of good pairs.
//
// A pair (i, j) is called good if nums[i] == nums[j] and i < j.
//
//
// Example 1:
//
//
//Input: nums = [1,2,3,1,1,3]
//Output: 4
//Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
//
//
// Example 2:
//
//
//Input: nums = [1,1,1,1]
//Output: 6
//Explanation: Each pair in the array are good.
//
//
// Example 3:
//
//
//Input: nums = [1,2,3]
//Output: 0
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100
//
//
// Related Topics Array Hash Table Math Counting 👍 4778 👎 212
#include <unordered_map>
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static int numIdenticalPairs(vector<int> &A)
    {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x: A)
        {
            ans += cnt[x];
            cnt[x]++;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
