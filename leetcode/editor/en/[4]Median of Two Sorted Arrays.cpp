/**
Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
the median of the two sorted arrays. 

 The overall run time complexity should be O(log (m+n)). 

 
 Example 1: 

 
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
 

 Example 2: 

 
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

 
 Constraints: 

 
 nums1.length == m 
 nums2.length == n 
 0 <= m <= 1000 
 0 <= n <= 1000 
 1 <= m + n <= 2000 
 -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
 

 Related Topics Array Binary Search Divide and Conquer 👍 21343 👎 2406

*/
#include <vector>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    [[maybe_unused]] double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int target = (int) (nums1.size() + nums2.size()) / 2;
        int tag = (int) (nums1.size() + nums2.size()) % 2;
        int ans;
        for (int i = 0; i < target; ++i)
        {
            ans = NextValue(nums1, nums2);
        }
        if (tag == 0)
        {
            ans += NextValue(nums1, nums2);
            return ((double) ans / 2.0);
        } else
        {
            ans = NextValue(nums1, nums2);
            return ((double) ans);
        }
    }

private:
    int index1 = 0, index2 = 0;

    int NextValue(vector<int> &nums1, vector<int> &nums2)
    {
        if (index1 < nums1.size() && index2 < nums2.size())
        {
            return nums1[index1] > nums2[index2] ? nums2[index2++] : nums1[index1++];
        } else if (index1 >= nums1.size())
        {
            return nums2[index2++];
        } else if (index2 >= nums2.size())
        {
            return nums1[index1++];
        } else
        {
            return -99999;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
