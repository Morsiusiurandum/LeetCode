//You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
//You are given an array graph where graph[i] is a list of all the nodes connected
//with node i by an edge.
//
// Return the length of the shortest path that visits every node. You may start
//and stop at any node, you may revisit nodes multiple times, and you may reuse
//edges.
//
//
// Example 1:
//
//
//Input: graph = [[1,2,3],[0],[0],[0]]
//Output: 4
//Explanation: One possible path is [1,0,2,0,3]
//
//
// Example 2:
//
//
//Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
//Output: 4
//Explanation: One possible path is [0,1,4,2,3]
//
//
//
// Constraints:
//
//
// n == graph.length
// 1 <= n <= 12
// 0 <= graph[i].length < n
// graph[i] does not contain i.
// If graph[a] contains b, then graph[b] contains a.
// The input graph is always connected.
//
//
// Related Topics Dynamic Programming Bit Manipulation Breadth-First Search
//Graph Bitmask 👍 3787 👎 155
#include <queue>
#include <set>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // Class to carry three values at a time
    class tuple
    {
    public:
        int node;// on which current node we are standing
        int mask;// mask of that node
        int cost;// cost of path explore by this node
        tuple(int node, int mask, int cost)
        {
            this->node = node;
            this->mask = mask;
            this->cost = cost;
        }
    };


    static int shortestPathLength(vector<vector<int>> &graph)
    {
        // total number of nodes present
        int n = (int) graph.size();// extracting size of graph


        queue<tuple> q;// queue of class tuple type

        // set to take care which path we have already visited
        set<pair<int, int>> vis;

        int all = (1 << n) - 1;// if all nodes visited then

        // we don't know which node will give us shortest path so intially for all nodes we will store in our queue
        for (int i = 0; i < n; i++)
        {
            int maskValue = (1 << i);// 2 ^ i

            tuple thisNode(i, maskValue, 1);// make a tuple for every nod

            q.push(thisNode);// push tuple into our queue

            vis.insert({i, maskValue});// also update into our set
        }

        // Implementing BFS
        while (!q.empty())// until queue is not empty
        {
            tuple curr = q.front();// extracting front tuple
            q.pop();               // pop from queuu

            // if mask value becomes all, that means we have visited all of our nodes, so from here return cost - 1
            if (curr.mask == all)
            {
                return curr.cost - 1;
            }

            // if not, start exploring in its adjcant
            for (auto &adj: graph[curr.node])
            {
                int bothVisitedMask = curr.mask;// current mask

                // we are moving from one node o anthor node
                bothVisitedMask = bothVisitedMask | (1 << adj);

                // make tuple of this path
                tuple ThisNode(adj, bothVisitedMask, curr.cost + 1);

                // if this path is not explored i.e
                // if it is not present in our set then,
                if (vis.find({adj, bothVisitedMask}) == vis.end())
                {
                    vis.insert({adj, bothVisitedMask});// insert into set

                    q.push(ThisNode);// also insert into queue
                }
            }
        }

        // return -1, but this condition will never come
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
