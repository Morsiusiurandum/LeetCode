/**
You are given an m x n integer array grid where grid[i][j] could be: 

 
 1 representing the starting square. There is exactly one starting square. 
 2 representing the ending square. There is exactly one ending square. 
 0 representing empty squares we can walk over. 
 -1 representing obstacles that we cannot walk over. 
 

 Return the number of 4-directional walks from the starting square to the 
ending square, that walk over every non-obstacle square exactly once. 

 
 Example 1: 
 
 
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 

 Example 2: 
 
 
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 

 Example 3: 
 
 
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
 

 
 Constraints: 

 
 m == grid.length 
 n == grid[i].length 
 1 <= m, n <= 20 
 1 <= m * n <= 20 
 -1 <= grid[i][j] <= 2 
 There is exactly one starting cell and one ending cell. 
 

 Related Topics Array Backtracking Bit Manipulation Matrix 👍 3815 👎 153

*/
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int path(int i, int j, int n, int m, int &c, int cnt, vector<vector<int>> &grid)
    {
        if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == -1 or grid[i][j] == 3)
            return 0;

        // ending square
        if (grid[i][j] == 2)
        {
            //if all empty cells visited then returning 1 else 0
            if (cnt - 1 == c) return 1;
            return 0;
        }

        grid[i][j] = 3;                                          // mark as visited

        // all possible paths
        int up = path(i - 1, j, n, m, c, cnt + 1, grid);
        int down = path(i + 1, j, n, m, c, cnt + 1, grid);
        int left = path(i, j - 1, n, m, c, cnt + 1, grid);
        int right = path(i, j + 1, n, m, c, cnt + 1, grid);

        grid[i][j] = 0;                                          // mark as unvisited

        return up + down + left + right;                             // total count of reaching ending square
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        int st, en;
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if it is starting square
                if (grid[i][j] == 1)
                {
                    st = i;
                    en = j;
                }

                // count of empty cells
                if (grid[i][j] == 0)
                {
                    c++;
                }
            }
        }
        return path(st, en, n, m, c, 0, grid);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
