//Given an integer n, return a list of all possible full binary trees with n 
//nodes. Each node of each tree in the answer must have Node.val == 0. 
//
// Each element of the answer is the root node of one possible tree. You may 
//return the final list of trees in any order. 
//
// A full binary tree is a binary tree where each node has exactly 0 or 2 
//children. 
//
// 
// Example 1: 
// 
// 
//Input: n = 7
//Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,
//0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// 
//
// Example 2: 
//
// 
//Input: n = 3
//Output: [[0,0,0]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics Dynamic Programming Tree Recursion Memoization Binary Tree
// 👍4252 👎 287
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        // If n is even => there is no complete binary tree with number of nodes = n
        if (n % 2 == 0) return {};

        vector<TreeNode *> list;
        if (n == 1)
        {
            list.push_back(new TreeNode(0));
        }
        else
        {
            for (int i = 1; i <= n - 1; i += 2)
            {
                vector<TreeNode *> left_tree = allPossibleFBT(i);
                vector<TreeNode *> right_tree = allPossibleFBT(n - i - 1);

                for (TreeNode *lt: left_tree)
                {
                    for (TreeNode *rt: right_tree)
                    {
                        list.push_back(new TreeNode(0, lt, rt));
                    }
                }
            }
        }
        return list;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
