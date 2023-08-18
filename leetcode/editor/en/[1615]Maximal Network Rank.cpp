//There is an infrastructure of n cities with some number of roads connecting 
//these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional 
//road between cities ai and bi. 
//
// The network rank of two different cities is defined as the total number of 
//directly connected roads to either city. If a road is directly connected to both 
//cities, it is only counted once. 
//
// The maximal network rank of the infrastructure is the maximum network rank 
//of all pairs of different cities. 
//
// Given the integer n and the array roads, return the maximal network rank of 
//the entire infrastructure. 
//
// 
// Example 1: 
//
// 
//
// 
//Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
//Output: 4
//Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads 
//that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
// 
//
// Example 2: 
//
// 
//
// 
//Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
//Output: 5
//Explanation: There are 5 roads that are connected to cities 1 or 2.
// 
//
// Example 3: 
//
// 
//Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
//Output: 5
//Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do 
//not have to be connected.
// 
//
// 
// Constraints: 
//
// 
// 2 <= n <= 100 
// 0 <= roads.length <= n * (n - 1) / 2 
// roads[i].length == 2 
// 0 <= ai, bi <= n-1 
// ai != bi 
// Each pair of cities has at most one road connecting them. 
// 
//
// Related Topics Graph 👍 1872 👎 293

#include <vector>
#include <queue>

using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    static int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> degrees(n);
        for (const vector<int> &road: roads)
        {
            int a = road[0];
            int b = road[1];
            ++degrees[a];
            ++degrees[b];
        }

        int max_degree = 0;
        int second_max_degree = 0;
        for (int degree: degrees)
        {
            if (degree < second_max_degree)
            {
                continue;
            }
            second_max_degree = degree;
            if (second_max_degree > max_degree)
            {
                swap(second_max_degree, max_degree);
            }
        }

        vector<bool> is_candidate(n);
        int candidate_count = 0;
        int king = -1;
        for (int i = 0; i < n; ++i)
        {
            if (degrees[i] == second_max_degree)
            {
                is_candidate[i] = true;
                ++candidate_count;
            }
            if (max_degree > second_max_degree && degrees[i] == max_degree)
            {
                king = i;
            }
        }

        if (max_degree == second_max_degree)
        {
            // Case 1: We have multiple candidates with the same max degrees.
            if (candidate_count > max_degree + 1)
            {
                return max_degree * 2;
            }
            int connection_count = 0;
            for (const vector<int> &road: roads)
            {
                int a = road[0];
                int b = road[1];
                if (is_candidate[a] && is_candidate[b])
                {
                    ++connection_count;
                }
            }
            if (connection_count < candidate_count * (candidate_count - 1) / 2)
            {
                return max_degree * 2;
            }
            return max_degree * 2 - 1;
        }

        // Case 2: We have a single max degree (king) and multiple second max degree candidates.
        int connection_count = 0;
        for (const vector<int> &road: roads)
        {
            int a = road[0];
            int b = road[1];
            if (a != king && b != king)
                continue;

            if (is_candidate[a] || is_candidate[b])
            {
                ++connection_count;
            }
        }
        if (connection_count < candidate_count)
        {
            return max_degree + second_max_degree;
        }
        return max_degree + second_max_degree - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
