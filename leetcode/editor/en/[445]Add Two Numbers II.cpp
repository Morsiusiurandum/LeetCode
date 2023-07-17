//You are given two non-empty linked lists representing two non-negative 
//integers. The most significant digit comes first and each of their nodes contains a 
//single digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the 
//number 0 itself. 
//
// 
// Example 1: 
// 
// 
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
// 
//
// Example 2: 
//
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
// 
//
// Example 3: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in each linked list is in the range [1, 100]. 
// 0 <= Node.val <= 9 
// It is guaranteed that the list represents a number that does not have 
//leading zeros. 
// 
//
// 
// Follow up: Could you solve it without reversing the input lists? 
//
// Related Topics Linked List Math Stack 👍 5142 👎 258

#include <stack>

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;

        //Push in the stack
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        //Carry flag
        bool carry = false;
        int temp;
        auto head = new ListNode();
        ListNode *prev;

        while (!s1.empty() || !s2.empty())
        {
            //Reset temp
            temp = 0;

            //Add the number of list and carry
            if (!s1.empty())
            {
                temp += s1.top();
                s1.pop();
            }

            if (!s2.empty())
            {
                temp += s2.top();
                s2.pop();
            }
            temp += carry;

            //Separate tens and ones
            carry = temp / 10;
            temp = temp % 10;

            //Push ones into the ans
            prev = new ListNode(temp);
            prev->next = head->next;
            head->next = prev;
        }

        if (carry)
        {
            prev = new ListNode(carry);
            prev->next = head->next;
            head->next = prev;
        }

        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
