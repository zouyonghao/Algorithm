/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (29.57%)
 * Total Accepted:    14.4K
 * Total Submissions: 49.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* next = first;
        for (int i = 0; i < n + 1; i++) {
            next = next->next;
        }
        while (next != nullptr) {
            first = first->next;
            next = next->next;
        }
        if (first->next == head) {
            return head->next;
        }
        if (first->next != nullptr)
            first->next = first->next->next;
        return head;
    }
};
