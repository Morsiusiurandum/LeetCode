/**
You are given a 0-indexed integer array tasks, where tasks[i] represents the
difficulty level of a task. In each round, you can complete either 2 or 3 tasks of
the same difficulty level. 

Return the minimum rounds required to complete all the tasks, or -1 if it is
not possible to complete all the tasks.

 
Example 1:

 
Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
 

Example 2:

 
Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you 
can only complete either 2 or 3 tasks of the same difficulty level. Hence, you 
cannot complete all the tasks, and the answer is -1.
 

 
 Constraints: 

 
 1 <= tasks.length <= 10⁵ 
 1 <= tasks[i] <= 10⁹ 
 

 Related Topics Array Hash Table Greedy Counting 👍 1586 👎 45

*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> task_cache;
        int ans = 0;
        for (int task: tasks)
        {
            if (task_cache.find(task) == task_cache.end())
            {
                task_cache[task] = 1;
            } else
            {
                task_cache[task]++;
            }
        }
        for (const auto &item: task_cache)
        {
            if (item.second == 1) return -1;
            if (item.second == 2 || item.second == 3)
            {
                ans++;
            } else
            {
                //e.g.
                //7 needs (7/3)+1 = 3 round (3,2,2)
                //thanks to qiushile!
                ans += (item.second + 2) / 3;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
