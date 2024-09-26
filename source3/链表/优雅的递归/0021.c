/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 若L1 < L2 ,则合并L1和L2变成了考虑子合并L1->next和L2；反之相同
// 时间复杂度 O(M+N) 空间复杂度 O(M+N)
// 没有直接双指针暴力求解来的好，但是思想值得学习
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}


ListNode* mergeTwoLists2(ListNode *a, ListNode *b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
        if (aPtr->val < bPtr->val) {
            tail->next = aPtr; aPtr = aPtr->next;
        } else {
            tail->next = bPtr; bPtr = bPtr->next;
        }
        tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
}