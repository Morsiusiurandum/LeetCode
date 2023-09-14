//You are given a list of airline tickets where tickets[i] = [fromi, toi]
//represent the departure and the arrival airports of one flight. Reconstruct the
//itinerary in order and return it.
//
// All of the tickets belong to a man who departs from "JFK", thus, the
//itinerary must begin with "JFK". If there are multiple valid itineraries, you should
//return the itinerary that has the smallest lexical order when read as a single
//string.
//
//
// For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than [
//"JFK", "LGB"].
//
//
// You may assume all tickets form at least one valid itinerary. You must use
//all the tickets once and only once.
//
//
// Example 1:
//
//
//Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//Output: ["JFK","MUC","LHR","SFO","SJC"]
//
//
// Example 2:
//
//
//Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],[
//"ATL","SFO"]]
//Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK",
//"ATL","SFO"] but it is larger in lexical order.
//
//
//
// Constraints:
//
//
// 1 <= tickets.length <= 300
// tickets[i].length == 2
// fromi.length == 3
// toi.length == 3
// fromi and toi consist of uppercase English letters.
// fromi != toi
//
//
// Related Topics Depth-First Search Graph Eulerian Circuit 👍 5304 👎 1757
#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] static vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, vector<string>> graph;

        for (auto &ticket: tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }

        for (auto &[_, destinations]: graph) {
            sort(destinations.rbegin(), destinations.rend());
        }

        vector<string> itinerary;

        function<void(const string &)> dfs = [&](const string &airport) {
            while (!graph[airport].empty()) {
                string next = graph[airport].back();
                graph[airport].pop_back();
                dfs(next);
            }
            itinerary.push_back(airport);
        };

        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
