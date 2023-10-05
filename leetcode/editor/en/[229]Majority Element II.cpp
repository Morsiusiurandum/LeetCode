//Given an integer array of size n, find all elements that appear more than ⌊ n/
//3 ⌋ times.
//
//
// Example 1:
//
//
//Input: nums = [3,2,3]
//Output: [3]
//
//
// Example 2:
//
//
//Input: nums = [1]
//Output: [1]
//
//
// Example 3:
//
//
//Input: nums = [1,2]
//Output: [1,2]
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 5 * 10⁴
// -10⁹ <= nums[i] <= 10⁹
//
//
//
// Follow up: Could you solve the problem in linear time and in O(1) space?
//
// Related Topics Array Hash Table Sorting Counting 👍 8780 👎 382
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto &num: nums) {
            if (vote1 > 0 && num == element1)
            {
                vote1++;
            }
            else if (vote2 > 0 && num == element2)
            {
                vote2++;
            }
            else if (vote1 == 0)
            {
                element1 = num;
                vote1++;
            }
            else if (vote2 == 0)
            {
                element2 = num;
                vote2++;
            }
            else {
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto &num: nums)
        {
            if (vote1 > 0 && num == element1)
            {
                cnt1++;
            }
            if (vote2 > 0 && num == element2)
            {
                cnt2++;
            }
        }

        if (vote1 > 0 && cnt1 > nums.size() / 3)
        {
            ans.push_back(element1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3)
        {
            ans.push_back(element2);
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
