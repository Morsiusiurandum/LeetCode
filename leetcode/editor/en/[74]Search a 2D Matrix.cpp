//You are given an m x n integer matrix matrix with the following two 
//properties: 
//
// 
// Each row is sorted in non-decreasing order. 
// The first integer of each row is greater than the last integer of the 
//previous row. 
// 
//
// Given an integer target, return true if target is in matrix or false 
//otherwise. 
//
// You must write a solution in O(log(m * n)) time complexity. 
//
// 
// Example 1: 
// 
// 
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
// 
//
// 
// Constraints: 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -10⁴ <= matrix[i][j], target <= 10⁴ 
// 
//
// Related Topics Array Binary Search Matrix 👍 13739 👎 371
#include<vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    // Maybe
    // Double Binary Search
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
                return true;
            else if (mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
