//Given the root of a binary tree, the value of a target node target, and an 
//integer k, return an array of the values of all nodes that have a distance k from 
//the target node. 
//
// You can return the answer in any order. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 
//5) have values 7, 4, and 1.
// 
//
// Example 2: 
//
// 
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 500]. 
// 0 <= Node.val <= 500 
// All the values Node.val are unique. 
// target is the value of one of the nodes in the tree. 
// 0 <= k <= 1000 
// 
//
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree
// 👍 9434 👎 179

#include <vector>
#include <unordered_map>
#include <queue>

#define NULL nullptr
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    //Directed acyclic graph to undirected acyclic graph
public:
    void buildGraph(TreeNode *root, unordered_map<int, vector<int>> &graph)
    {

        if (root->left != NULL)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }
        if (root->right != NULL)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {

        if (K == 0) return {target->val};

        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        vector<int> res;
        queue<int> q;
        int cnt = 0;


        buildGraph(root, graph);
        q.push(target->val);
        while (!q.empty())
        {
            auto sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int curr = q.front();
                q.pop();
                visited[curr] = true;

                for (int x: graph[curr])
                {
                    if (!visited[x]) q.push(x);
                }
            }
            cnt++;

            if (cnt == K)
            {
                while (!q.empty())
                {
                    res.push_back(q.front());
                    q.pop();
                }
                break;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
