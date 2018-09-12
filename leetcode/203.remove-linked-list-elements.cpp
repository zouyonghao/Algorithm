/*
 * [203] Remove Linked List Elements
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (38.13%)
 * Total Accepted:    5.8K
 * Total Submissions: 15.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode* tmp = head;
        while (tmp->next != NULL) {
            if (tmp->next->val == val) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        if (head->val == val) {
            head = head->next;
        }
        return head;
    }
};
