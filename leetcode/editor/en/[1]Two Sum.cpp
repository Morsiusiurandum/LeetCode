/**
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target. 

 You may assume that each input would have exactly one solution, and you may 
not use the same element twice. 

 You can return the answer in any order. 

 
 Example 1: 

 
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 

 Example 2: 

 
Input: nums = [3,2,4], target = 6
Output: [1,2]
 

 Example 3: 

 
Input: nums = [3,3], target = 6
Output: [0,1]
 

 
 Constraints: 

 
 2 <= nums.length <= 10⁴ 
 -10⁹ <= nums[i] <= 10⁹ 
 -10⁹ <= target <= 10⁹ 
 Only one valid answer exists. 
 

 
Follow-up: Can you come up with an algorithm that is less than 
O(n²) time complexity?

 Related Topics Array Hash Table 👍 41710 👎 1362

*/
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    //Use a hash table to temporarily store traversed elements for quick lookup
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int needed;
        map<int, int> cache_map;
        //nums traverses only once
        for (int i = 0; i < nums.size(); i++)
        {
            needed = target - nums[i];
            if (cache_map.count(needed))
            {
                //Throw the answer when find
                return {i, cache_map[needed]};
            } else
            {
                cache_map.insert(make_pair(nums[i], i));
            }
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
