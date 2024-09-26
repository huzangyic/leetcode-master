/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 合并K个升序链表， 0021.c的升级版

// 方法一：思路

// 我们可以想到一种最朴素的方法：用一个变量 ans 来维护以及合并的链表，第 i 次循环把第 i 个链表和 ans 合并，答案保存到 ans 中。
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (listsSize == 0) {
        return NULL;
    }
    if (listsSize < 2) {
        return lists[0];
    }

    struct ListNode* result = lists[0];
    for (int j = 1; j < listsSize; j++) {
        result = mergeTwoLists(result, lists[j]);
    }
    return result;
}


// 方法二： 