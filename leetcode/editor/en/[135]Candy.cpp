//There are n children standing in a line. Each child is assigned a rating
//value given in the integer array ratings.
//
// You are giving candies to these children subjected to the following
//requirements:
//
//
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
//
//
// Return the minimum number of candies you need to have to distribute the
//candies to the children.
//
//
// Example 1:
//
//
//Input: ratings = [1,0,2]
//Output: 5
//Explanation: You can allocate to the first, second and third child with 2, 1,
//2 candies respectively.
//
//
// Example 2:
//
//
//Input: ratings = [1,2,2]
//Output: 4
//Explanation: You can allocate to the first, second and third child with 1, 2,
//1 candies respectively.
//The third child gets 1 candy because it satisfies the above two conditions.
//
//
//
// Constraints:
//
//
// n == ratings.length
// 1 <= n <= 2 * 10⁴
// 0 <= ratings[i] <= 2 * 10⁴
//
//
// Related Topics Array Greedy 👍 6753 👎 496
#include <vector>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int candy(vector<int> &ratings)
    {
        int n = (int) ratings.size();
        vector<int> left(n + 1, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        int right = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right++;
                left[i] = max(left[i], right);
            }
            else {
                right = 1;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += left[i];
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
