//Given n orders,each order consists of a pickup and a delivery service.
//
// Count all valid pickup/delivery possible sequences such that delivery(i) is
//always after of pickup(i).
//
// Since the answer may be too large, return it modulo 10^9 + 7.
//
//
// Example 1:
//
//
//Input: n = 1
//Output: 1
//Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
//
//
// Example 2:
//
//
//Input: n = 2
//Output: 6
//Explanation: All possible orders:
//(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and
//(P2,D2,P1,D1).
//This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2
//.
//
//
// Example 3:
//
//
//Input: n = 3
//Output: 90
//
//
//
// Constraints:
//
//
// 1 <= n <= 500
//
//
// Related Topics Math Dynamic Programming Combinatorics 👍 2918 👎 216


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int MOD = 1e9 + 7;
    [[nodiscard]] int countOrders(int n) const
    {
        long places = 2 * n;
        long seq = 1;
        for (int i = n; i >= 1; i--) {
            seq = (seq * ((places * (places - 1)) / 2)) % MOD;
            places = places - 2;
        }
        return (int) seq;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
