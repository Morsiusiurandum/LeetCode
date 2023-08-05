//Given an integer n, return all the structurally unique BST's (binary search 
//trees), which has exactly n nodes of unique values from 1 to n. Return the answer 
//in any order. 
//
// 
// Example 1: 
// 
// 
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]
//]
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: [[1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics Dynamic Programming Backtracking Tree Binary Search Tree 
//Binary Tree 👍 6804 👎 440

#include<vector>

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
    vector<TreeNode *> BinarySearchTree(int start, int end)
    {
        if (start > end)
        {
            return {nullptr};
        }

        vector<TreeNode *> allTrees;

        for (int i = start; i <= end; i++)
        {
            // left tree list
            vector<TreeNode *> leftTrees = BinarySearchTree(start, i - 1);
            // right tree list
            vector<TreeNode *> rightTrees = BinarySearchTree(i + 1, end);

            for (TreeNode *&left: leftTrees)
            {
                for (TreeNode *&right: rightTrees)
                {
                    auto *currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        else
        {
            return BinarySearchTree(1, n);
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
