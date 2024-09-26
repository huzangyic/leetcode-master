
// 我自己的做法： 比较朴素
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { // 0个元素 or 1个元素
        return head;
    }

    struct ListNode *prev = head;
    struct ListNode *post = head->next;
    // printf("head is %d, prev is %d, post is %d\n", head->val, prev->val, post->val);

    head = post;
    prev->next = post->next;
    post->next = prev;
    // printf("prev->next is %d\n", prev->val);

    prev->next = swapPairs(prev->next);

    return head;
}


// 看完题解后的做法
// 递归两个要素：
// 1）递归终止条件：链表中没有节点，或者链表中只有一个节点，此时无法进行交换。
// 2）递归实现，交换节点时，余下的节点可以视作一个整体
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}