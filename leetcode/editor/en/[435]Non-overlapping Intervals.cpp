//Given an array of intervals intervals where intervals[i] = [starti, endi], 
//return the minimum number of intervals you need to remove to make the rest of the 
//intervals non-overlapping. 
//
// 
// Example 1: 
//
// 
//Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
//Output: 1
//Explanation: [1,3] can be removed and the rest of the intervals are non-
//overlapping.
// 
//
// Example 2: 
//
// 
//Input: intervals = [[1,2],[1,2],[1,2]]
//Output: 2
//Explanation: You need to remove two [1,2] to make the rest of the intervals 
//non-overlapping.
// 
//
// Example 3: 
//
// 
//Input: intervals = [[1,2],[2,3]]
//Output: 0
//Explanation: You don't need to remove any of the intervals since they're 
//already non-overlapping.
// 
//
// 
// Constraints: 
//
// 
// 1 <= intervals.length <= 10⁵ 
// intervals[i].length == 2 
// -5 * 10⁴ <= starti < endi <= 5 * 10⁴ 
// 
//
// Related Topics Array Dynamic Programming Greedy Sorting 👍 6820 👎 178

#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static bool compare(vector<int> &v1, vector<int> &v2)
    {
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        int res = 0, prev = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            intervals[prev][1] > intervals[i][0] ? res++ : prev = i;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
