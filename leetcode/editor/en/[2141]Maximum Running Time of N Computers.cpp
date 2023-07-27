//You have n computers. You are given the integer n and a 0-indexed integer 
//array batteries where the iᵗʰ battery can run a computer for batteries[i] minutes. 
//You are interested in running all n computers simultaneously using the given 
//batteries. 
//
// Initially, you can insert at most one battery into each computer. After that 
//and at any integer time moment, you can remove a battery from a computer and 
//insert another battery any number of times. The inserted battery can be a totally 
//new battery or a battery from another computer. You may assume that the removing 
//and inserting processes take no time. 
//
// Note that the batteries cannot be recharged. 
//
// Return the maximum number of minutes you can run all the n computers 
//simultaneously. 
//
// 
// Example 1: 
// 
// 
//Input: n = 2, batteries = [3,3,3]
//Output: 4
//Explanation: 
//Initially, insert battery 0 into the first computer and battery 1 into the 
//second computer.
//After two minutes, remove battery 1 from the second computer and insert 
//battery 2 instead. Note that battery 1 can still run for one minute.
//At the end of the third minute, battery 0 is drained, and you need to remove 
//it from the first computer and insert battery 1 instead.
//By the end of the fourth minute, battery 1 is also drained, and the first 
//computer is no longer running.
//We can run the two computers simultaneously for at most 4 minutes, so we 
//return 4.
// 
//
//
// Example 2: 
// 
// 
//Input: n = 2, batteries = [1,1,1,1]
//Output: 2
//Explanation: 
//Initially, insert battery 0 into the first computer and battery 2 into the 
//second computer. 
//After one minute, battery 0 and battery 2 are drained so you need to remove 
//them and insert battery 1 into the first computer and battery 3 into the second 
//computer. 
//After another minute, battery 1 and battery 3 are also drained so the first 
//and second computers are no longer running.
//We can run the two computers simultaneously for at most 2 minutes, so we 
//return 2.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= batteries.length <= 10⁵ 
// 1 <= batteries[i] <= 10⁹ 
// 
//
// Related Topics Array Binary Search Greedy Sorting 👍 1450 👎 38
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
    /*
    *Sort the batteries in ascending order to have the highest capacity battery at the end.
    *Calculate the sum of all the batteries (sum).
    *Initialize a pointer i to the end of the sorted battery array (m-1)
    *While i is greater than or equal to 0 and the average capacity of the remaining batteries (sum/n) is less than the capacity of the battery at index i, we do the following:
    *Subtract the capacity of the battery at index i from the total sum (sum).
    *Decrement the number of computers (n) by 1.
    *Decrement the pointer i by 1.
    *The answer is the remaining sum of battery capacities divided by the number of computers (sum/n).
    *----Jai Shree Ram
    */
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        int m = (int) batteries.size();
        sort(batteries.begin(), batteries.end());
        long long sum = accumulate(begin(batteries), end(batteries), 0LL);
        int i = m - 1;
        while (i >= 0 && sum / n < batteries[i])
        {
            sum -= batteries[i];
            n--;
            i--;
        }
        return sum / n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
