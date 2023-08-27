//A frog is crossing a river. The river is divided into some number of units, 
//and at each unit, there may or may not exist a stone. The frog can jump on a 
//stone, but it must not jump into the water. 
//
// Given a list of stones' positions (in units) in sorted ascending order, 
//determine if the frog can cross the river by landing on the last stone. Initially, 
//the frog is on the first stone and assumes the first jump must be 1 unit. 
//
// If the frog's last jump was k units, its next jump must be either k - 1, k, 
//or k + 1 units. The frog can only jump in the forward direction. 
//
// 
// Example 1: 
//
// 
//Input: stones = [0,1,3,5,6,8,12,17]
//Output: true
//Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd 
//stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 
//units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
// 
//
// Example 2: 
//
// 
//Input: stones = [0,1,2,3,4,8,9,11]
//Output: false
//Explanation: There is no way to jump to the last stone as the gap between the 
//5th and 6th stone is too large.
// 
//
// 
// Constraints: 
//
// 
// 2 <= stones.length <= 2000 
// 0 <= stones[i] <= 2³¹ - 1 
// stones[0] == 0 
// stones is sorted in a strictly increasing order. 
// 
//
// Related Topics Array Dynamic Programming 👍 4812 👎 225
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    unordered_map<int, int> m;
    int dp[2000][2000]{};

    int solve(int i, int k, vector<int> &stones)
    {
        if (i == stones.size() - 1)
        {
            return true;
        }

        if (dp[i][k] != -1)
        {
            return dp[i][k];
        }

        bool k0 = false;
        bool kp = false;
        bool k1 = false;

        if (m.find(stones[i] + k) != m.end())
        {
            k0 = solve(m[stones[i] + k], k, stones);
        }
        if (k > 1 && m.find(stones[i] + k - 1) != m.end())
        {
            kp = solve(m[stones[i] + k - 1], k - 1, stones);
        }
        if (m.find(stones[i] + k + 1) != m.end())
        {
            k1 = solve(m[stones[i] + k + 1], k + 1, stones);
        }

        dp[i][k] = k0 || kp || k1;
        return dp[i][k];
    }

    bool canCross(vector<int> &stones)
    {
        if (stones[1] - stones[0] != 1)
        {
            return false;
        }

        for (int i = 0; i < stones.size(); i++)
        {
            m[stones[i]] = i;
        }

        memset(dp, -1, sizeof(dp));

        return solve(1, 1, stones);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
