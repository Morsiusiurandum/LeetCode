//On an n x n chessboard, a knight starts at the cell (row, column) and 
//attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left 
//cell is (0, 0), and the bottom-right cell is (n - 1, n - 1). 
//
// A chess knight has eight possible moves it can make, as illustrated below. 
//Each move is two cells in a cardinal direction, then one cell in an orthogonal 
//direction. 
// 
// Each time the knight is to move, it chooses one of eight possible moves 
//uniformly at random (even if the piece would go off the chessboard) and moves there. 
//
//
// The knight continues moving until it has made exactly k moves or has moved 
//off the chessboard. 
//
// Return the probability that the knight remains on the board after it has 
//stopped moving. 
//
// 
// Example 1: 
//
// 
//Input: n = 3, k = 2, row = 0, column = 0
//Output: 0.06250
//Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight 
//on the board.
//From each of those positions, there are also two moves that will keep the 
//knight on the board.
//The total probability the knight stays on the board is 0.0625.
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 0, row = 0, column = 0
//Output: 1.00000
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 25 
// 0 <= k <= 100 
// 0 <= row, column <= n - 1 
// 
//
// Related Topics Dynamic Programming 👍 3185 👎 407

#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<double>> dp(n, vector<double>(n, 0));

        //start place
        dp[row][column] = 1;

        //eight move directions
        const vector<vector<int>> move_steps =
                {
                        {-2, -1},
                        {-2, +1},
                        {-1, -2},
                        {-1, +2},
                        {+1, -2},
                        {+1, +2},
                        {+2, -1},
                        {+2, +1}
                };


        for (int move = 1; move <= k; move++)
        {
            vector<vector<double>> dp_new_step(n, vector<double>(n, 0));

            /*
             * r-row
             * c-column
             */

            for (int r = 0; r < n; r++)
            {
                for (int c = 0; c < n; c++)
                {
                    for (const auto &step: move_steps)
                    {
                        int next_r = r + step[0];
                        int next_c = c + step[1];

                        //the probability of the previous step increases
                        if (inBoard(next_r, next_c, n))
                        {
                            dp_new_step[r][c] += dp[next_r][next_c] / 8.;
                        }
                    }
                }
            }
            dp = dp_new_step;
        }

        double probability = 0;
        //collection the probability
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                probability += dp[r][c];
            }
        }

        return probability;
    }

    //return true if in the board
    static bool inBoard(int r, int c, int n)
    {
        return (0 <= r && r < n) && (0 <= c && c < n);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
