//Given an integer rowIndex, return the rowIndexᵗʰ (0-indexed) row of the
//Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly
//above it as shown:
//
//
// Example 1:
// Input: rowIndex = 3
//Output: [1,3,3,1]
//
// Example 2:
// Input: rowIndex = 0
//Output: [1]
//
// Example 3:
// Input: rowIndex = 1
//Output: [1,1]
//
//
// Constraints:
//
//
// 0 <= rowIndex <= 33
//
//
//
// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
//space?
//
// Related Topics Array Dynamic Programming 👍 4463 👎 316
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 1, 1);

        for (int i = 1; i <= rowIndex / 2; i++) {
            result[i] = (long)result[i - 1] * (rowIndex - i + 1) / i;
            result[rowIndex - i] = result[i];
        }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
