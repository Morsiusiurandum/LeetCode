//You are given an array points representing integer coordinates of some points
//on a 2D-plane, where points[i] = [xi, yi].
//
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
//distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute
//value of val.
//
// Return the minimum cost to make all points connected. All points are
//connected if there is exactly one simple path between any two points.
//
//
// Example 1:
//
//
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation:
//
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//
//
// Example 2:
//
//
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
//
//
//
// Constraints:
//
//
// 1 <= points.length <= 1000
// -10⁶ <= xi, yi <= 10⁶
// All pairs (xi, yi) are distinct.
//
//
// Related Topics Array Union Find Graph Minimum Spanning Tree 👍 4407 👎 101
#include <valarray>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<int> parent;
        vector<pair<int, pair<int, int>>> edges;
        int n = (int) points.size();

        parent.reserve(n);
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        int min_cost = 0, num_edges = 0;

        for (auto &edge: edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (find(parent, u) != find(parent, v)) {
                unionSets(parent, u, v);
                min_cost += cost;
                num_edges++;
            }

            if (num_edges == n - 1) {
                break;
            }
        }

        return min_cost;
    }

private:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void unionSets(vector<int> &parent, int x, int y)
    {
        parent[find(parent, x)] = find(parent, y);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
