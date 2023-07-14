//Given an integer array arr and an integer difference, return the length of 
//the longest subsequence in arr which is an arithmetic sequence such that the 
//difference between adjacent elements in the subsequence equals difference. 
//
// A subsequence is a sequence that can be derived from arr by deleting some or 
//no elements without changing the order of the remaining elements. 
//
// 
// Example 1: 
//
// 
//Input: arr = [1,2,3,4], difference = 1
//Output: 4
//Explanation: The longest arithmetic subsequence is [1,2,3,4]. 
//
// Example 2: 
//
// 
//Input: arr = [1,3,5,7], difference = 1
//Output: 1
//Explanation: The longest arithmetic subsequence is any single element.
// 
//
// Example 3: 
//
// 
//Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
//Output: 4
//Explanation: The longest arithmetic subsequence is [7,5,3,1].
// 
//
// 
// Constraints: 
//
// 
// 1 <= arr.length <= 10⁵ 
// -10⁴ <= arr[i], difference <= 10⁴ 
// 
//
// Related Topics Array Hash Table Dynamic Programming 👍 2456 👎 63

#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    // Easy dynamic programming
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // map[i]：Indicates the maximum length of the fixed difference subsequence of arr[0...i]
        unordered_map<int, int> map;
        int ans = 1;
        for (auto x: arr)
        {
            //Use the calculated value:map[i-diff] for dynamic programming and set
            map[x] = map.count(x - difference) ? map[x - difference] + 1 : 1;
            //Select the best answer
            ans = max(ans, map[x]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
