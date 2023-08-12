//You are given an m x n integer array grid. There is a robot initially located 
//at the top-left corner (i.e., grid[0][0]). The robot tries to move to the 
//bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down 
//or right at any point in time. 
//
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that 
//the robot takes cannot include any square that is an obstacle. 
//
// Return the number of possible unique paths that the robot can take to reach 
//the bottom-right corner. 
//
// The testcases are generated so that the answer will be less than or equal to 
//2 * 10⁹. 
//
// 
// Example 1: 
// 
// 
//Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//Output: 2
//Explanation: There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom-right corner:
//1. Right -> Right -> Down -> Down
//2. Down -> Down -> Right -> Right
// 
//
// Example 2: 
// 
// 
//Input: obstacleGrid = [[0,1],[0,0]]
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// m == obstacleGrid.length 
// n == obstacleGrid[i].length 
// 1 <= m, n <= 100 
// obstacleGrid[i][j] is 0 or 1. 
// 
//
// Related Topics Array Dynamic Programming Matrix 👍 7799 👎 465

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = (int) obstacleGrid.size();
        int n = (int) obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)return 0;
        vector<vector<long>> dp(m, vector<long>(n, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 2; i >= 0; i--)
        {
            if (obstacleGrid[i][n - 1] == 0)
                dp[i][n - 1] += dp[i + 1][n - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (obstacleGrid[m - 1][i] == 0)
                dp[m - 1][i] = dp[m - 1][i + 1];
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] += dp[i + 1][j];
                    dp[i][j] += dp[i][j + 1];
                }

            }
        }
        return dp[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
