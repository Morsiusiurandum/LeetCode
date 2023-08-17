//Given an m x n binary matrix mat, return the distance of the nearest 0 for 
//each cell. 
//
// The distance between two adjacent cells is 1. 
//
// 
// Example 1: 
// 
// 
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
// 
//
// Example 2: 
// 
// 
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//
// 
// Constraints: 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n <= 10⁴ 
// 1 <= m * n <= 10⁴ 
// mat[i][j] is either 0 or 1. 
// There is at least one 0 in mat. 
// 
//
// Related Topics Array Dynamic Programming Breadth-First Search Matrix 👍 8332 
//👎 373
#include <vector>
#include <queue>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = (int) mat.size();
        int m = (int) mat[0].size();
        vector<vector<int>> a(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!mat[i][j])q.emplace(i, j);
            }
        }
        int t = 0;
        while (q.size())
        {
            t++;
            int k = q.size();
            while (k--)
            {
                auto g = q.front();
                int x = g.first, y = g.second;
                q.pop();
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i], ny = dy[i] + y;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny])
                    {
                        mat[nx][ny] = 0;
                        a[nx][ny] = t;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
