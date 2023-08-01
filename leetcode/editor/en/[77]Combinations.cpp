//Given two integers n and k, return all possible combinations of k numbers 
//chosen from the range [1, n]. 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to 
//be the same combination.
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics Backtracking 👍 7042 👎 202
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    /* n: target length
     * k: remaining options
     * num: current preselected numbers
     */
    void solve(int n, int k, int num, vector<int> &sub_ans, vector<vector<int>> &ans)
    {
        //a sequence
        if (k == 0)
        {
            ans.push_back(sub_ans);
            return;
        }
        //out of bounds
        if (num == n + 1) return;

        // skip add element
        solve(n, k, num + 1, sub_ans, ans);

        // add element
        sub_ans.push_back(num);
        solve(n, k - 1, num + 1, sub_ans, ans);
        // backtrack
        sub_ans.pop_back();
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> sub_ans;

        solve(n, k, 1, sub_ans, ans);

        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
