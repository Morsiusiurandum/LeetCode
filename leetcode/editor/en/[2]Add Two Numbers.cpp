/**
You are given two non-empty linked lists representing two non-negative integers.
 The digits are stored in reverse order, and each of their nodes contains a 
single digit. Add the two numbers and return the sum as a linked list. 

 You may assume the two numbers do not contain any leading zero, except the 
number 0 itself. 

 
 Example 1: 
 
 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
 

 Example 2: 

 
Input: l1 = [0], l2 = [0]
Output: [0]
 

 Example 3: 

 
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

 
 Constraints: 

 
 The number of nodes in each linked list is in the range [1, 100]. 
 0 <= Node.val <= 9 
 It is guaranteed that the list represents a number that does not have leading 
zeros. 
 

 Related Topics Linked List Math Recursion 👍 23516 👎 4534

*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)


class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *answer = l1;
        int add = 0;
        for (; l1 != nullptr; l1 = l1->next)
        {
            //Make l1 be longest
            if (l1->next == nullptr && l2->next != nullptr)
            {
                l1->next = l2->next;
                l2->next = nullptr;
            }
            l1->val += l2->val;
            //Stop l2 pointer
            if (l2->next != nullptr)
            {
                l2 = l2->next;
            } else
            {
                l2->val = 0;
            }
            l1->val += add;
            add = l1->val / 10;
            l1->val %= 10;
            //extra carry
            if (l1->next == nullptr & add == 1)
            {
                l1->next = new ListNode(1);
                break;
            }
        }
        return answer;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
