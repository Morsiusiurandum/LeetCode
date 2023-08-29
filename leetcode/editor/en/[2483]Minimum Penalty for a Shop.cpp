//You are given the customer visit log of a shop represented by a 0-indexed 
//string customers consisting only of characters 'N' and 'Y': 
//
// 
// if the iᵗʰ character is 'Y', it means that customers come at the iᵗʰ hour 
// whereas 'N' indicates that no customers come at the iᵗʰ hour. 
// 
//
// If the shop closes at the jᵗʰ hour (0 <= j <= n), the penalty is calculated 
//as follows: 
//
// 
// For every hour when the shop is open and no customers come, the penalty 
//increases by 1. 
// For every hour when the shop is closed and customers come, the penalty 
//increases by 1. 
// 
//
// Return the earliest hour at which the shop must be closed to incur a minimum 
//penalty. 
//
// Note that if a shop closes at the jᵗʰ hour, it means the shop is closed at 
//the hour j. 
//
// 
// Example 1: 
//
// 
//Input: customers = "YYNY"
//Output: 2
//Explanation: 
//- Closing the shop at the 0ᵗʰ hour incurs in 1+1+0+1 = 3 penalty.
//- Closing the shop at the 1ˢᵗ hour incurs in 0+1+0+1 = 2 penalty.
//- Closing the shop at the 2ⁿᵈ hour incurs in 0+0+0+1 = 1 penalty.
//- Closing the shop at the 3ʳᵈ hour incurs in 0+0+1+1 = 2 penalty.
//- Closing the shop at the 4ᵗʰ hour incurs in 0+0+1+0 = 1 penalty.
//Closing the shop at 2ⁿᵈ or 4ᵗʰ hour gives a minimum penalty. Since 2 is 
//earlier, the optimal closing time is 2.
// 
//
// Example 2: 
//
// 
//Input: customers = "NNNNN"
//Output: 0
//Explanation: It is best to close the shop at the 0ᵗʰ hour as no customers 
//arrive. 
//
// Example 3: 
//
// 
//Input: customers = "YYYY"
//Output: 4
//Explanation: It is best to close the shop at the 4ᵗʰ hour as customers arrive 
//at each hour.
// 
//
// 
// Constraints: 
//
// 
// 1 <= customers.length <= 10⁵ 
// customers consists only of characters 'Y' and 'N'. 
// 
//
// Related Topics String Prefix Sum 👍 1256 👎 66

#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int bestClosingTime(string customers)
    {
        int max_score = 0, score = 0, best_hour = -1;
        for (int i = 0; i < customers.size(); ++i)
        {
            // When the store is open and has no customers: -1
            // When the store is closed and has customers: -1
            // So you can think: the default is -1 until something else happens
            score += (customers[i] == 'Y') ? 1 : -1;
            if (score > max_score)
            {
                max_score = score;
                best_hour = i;
            }
        }
        return best_hour + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
