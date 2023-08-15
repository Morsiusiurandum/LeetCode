//Given the head of a linked list and a value x, partition it such that all 
//nodes less than x come before nodes greater than or equal to x. 
//
// You should preserve the original relative order of the nodes in each of the 
//two partitions. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,4,3,2,5,2], x = 3
//Output: [1,2,2,4,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [2,1], x = 2
//Output: [1,2]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 200]. 
// -100 <= Node.val <= 100 
// -200 <= x <= 200 
// 
//
// Related Topics Linked List Two Pointers 👍 6508 👎 719



struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

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
    static ListNode *partition(ListNode *head, int x)
    {
        ListNode before(0), after(0);
        ListNode *before_curr = &before;
        ListNode *after_curr = &after;

        while (head)
        {
            if (head->val < x)
            {
                before_curr->next = head;
                before_curr = head;
            }
            else
            {
                after_curr->next = head;
                after_curr = head;
            }
            head = head->next;
        }

        after_curr->next = nullptr;
        before_curr->next = after.next;

        return before.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
