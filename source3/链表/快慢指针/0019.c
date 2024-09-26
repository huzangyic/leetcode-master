/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//  提示：

// 链表中结点的数目为 sz
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    // 一次循环就找到
    struct ListNode* fast = head;
    while (n > 0) {
        fast = fast->next;
        n--;
    }
    // 链表长度等于n
    if (fast == NULL) {
        head = head->next;
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* prev = head;
    while (fast != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = slow->next;

    return head;
}