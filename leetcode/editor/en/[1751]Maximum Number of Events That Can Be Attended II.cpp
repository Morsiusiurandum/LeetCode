//You are given an array of events where events[i] = [startDayi, endDayi, 
//valuei]. The iᵗʰ event starts at startDayi and ends at endDayi, and if you attend 
//this event, you will receive a value of valuei. You are also given an integer k 
//which represents the maximum number of events you can attend. 
//
// You can only attend one event at a time. If you choose to attend an event, 
//you must attend the entire event. Note that the end day is inclusive: that is, 
//you cannot attend two events where one of them starts and the other ends on the 
//same day. 
//
// Return the maximum sum of values that you can receive by attending events. 
//
// 
// Example 1: 
//
// 
//
// 
//Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
//Output: 7
//Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value 
//of 4 + 3 = 7. 
//
// Example 2: 
//
// 
//
// 
//Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
//Output: 10
//Explanation: Choose event 2 for a total value of 10.
//Notice that you cannot attend any other event as they overlap, and that you 
//do not have to attend k events. 
//
// Example 3: 
//
// 
//
// 
//Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
//Output: 9
//Explanation: Although the events do not overlap, you can only attend 3 events.
// Pick the highest valued three. 
//
// 
// Constraints: 
//
// 
// 1 <= k <= events.length 
// 1 <= k * events.length <= 10⁶ 
// 1 <= startDayi <= endDayi <= 10⁹ 
// 1 <= valuei <= 10⁶ 
// 
//
// Related Topics Array Binary Search Dynamic Programming Sorting 👍 1465 👎 25
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    // Very hard dynamic programming
public:
    static bool end_time_compare(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    static bool binary_search_compare(vector<int> &a, int val)
    {
        return a[1] < val;
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        auto len = events.size();

        // Sort meetings in ascending order by end time
        sort(events.begin(), events.end(), end_time_compare);

        int dp[len + 1][k + 1];
        memset(dp, 0, sizeof dp);
        /**
         * dp[i][j] : when considering the previous i conferences, the maximum sum of j conferences can be attended
         * dp[i][j] : max(Attend the i-th meeting, do not attend the i-th meeting)
         * dp[i][j] = max(dp[p][j-1]+v[i],dp[i-1][j])
         * Where p is the first (back-to-front) meeting whose end time is less than the start time of meeting i.
         */

        for (int i = 0; i < len; ++i)
        {
            // If p is the first meeting whose end time is greater than or equal to the start time of meeting i,
            // Then p-1 is the first meeting whose end time is less than the start time of meeting i.
            auto p = lower_bound(events.begin(), events.begin() + i, events[i][0], binary_search_compare) - events.begin();

            for (int j = 1; j <= k; ++j) dp[i + 1][j] = max(dp[i][j], dp[p][j - 1] + events[i][2]);
        }
        return dp[len][k];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
