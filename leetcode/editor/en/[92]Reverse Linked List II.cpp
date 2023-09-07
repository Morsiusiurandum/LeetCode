// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.
//
//
//  Example 1:
//
//
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
//
//
//  Example 2:
//
//
// Input: head = [5], left = 1, right = 1
// Output: [5]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is n.
//  1 <= n <= 500
//  -500 <= Node.val <= 500
//  1 <= left <= right <= n
//
//
//
// Follow up: Could you do it in one pass?
//
//  Related Topics Linked List 👍 10426 👎 473

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
public:
  [[maybe_unused]] static ListNode *reverseBetween(ListNode *head, int left,int right) {
    if (right == 1)
      return head;
    ListNode dummy = ListNode();
    ListNode *L = &dummy, *R;
    dummy.next = head;

    for (int i = 0; i < left - 1; i++)
      L = L->next;
    R = L->next;

    for (int i = left; i < right; i++) {
      ListNode *rev = R->next;
      R->next = rev->next;
      rev->next = L->next;
      L->next = rev;
    }

    return dummy.next;
  }
};
// leetcode submit region end(Prohibit modification and deletion)
