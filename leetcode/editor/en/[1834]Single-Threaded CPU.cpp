/**
You are given n tasks labeled from 0 to n - 1 represented by a 2D integer array 
tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the ith task 
will be available to process at enqueueTimei and will take processingTimei to 
finish processing. 

 You have a single-threaded CPU that can process at most one task at a time and 
will act in the following way: 

 
 If the CPU is idle and there are no available tasks to process, the CPU 
remains idle. 
 If the CPU is idle and there are available tasks, the CPU will choose the one 
with the shortest processing time. If multiple tasks have the same shortest 
processing time, it will choose the task with the smallest index. 
 Once a task is started, the CPU will process the entire task without stopping. 

 The CPU can finish a task then start a new one instantly. 
 

 Return the order in which the CPU will process the tasks. 

 
 Example 1: 

 
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.

- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it 
is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is 
the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available 
tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
 

 Example 2: 

 
Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,
1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available 
tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available 
tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available 
tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available 
tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.
 

 
 Constraints: 

 
 tasks.length == n 
 1 <= n <= 10⁵ 
 1 <= enqueueTimei, processingTimei <= 10⁹ 
 

 Related Topics Array Sorting Heap (Priority Queue) 👍 1201 👎 136

*/

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class comp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second > b.second)
        {
            return true;
        } else if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return false;
    }
};

class Solution
{
public:

    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        long currentTime = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> nextTask;
        vector<int> order;

        //add place information
        for (int i = 0; i < tasks.size(); i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());


        int i = 0;
        while (order.size() < tasks.size())
        {
            //add to nextTask
            while (i < tasks.size())
            {
                if (tasks[i][0] <= currentTime)
                {
                    nextTask.emplace(tasks[i][2], tasks[i][1]);
                    i++;
                } else
                {
                    break;
                }
            }

            if (!nextTask.empty())
            {
                //execution
                currentTime += nextTask.top().second;
                order.push_back(nextTask.top().first);
                nextTask.pop();
            } else
            {
                currentTime = tasks[i][0];
            }

        }
        return order;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
