/*
 * [206] Reverse Linked List
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (50.59%)
 * Total Accepted:    12.2K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    // use recurrence
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* list = reverseList(head->next);
        if (list != nullptr) {
            ListNode* tmp = list;
            while (tmp->next) tmp = tmp->next;
            tmp->next = head;
            tmp->next->next = nullptr;
        } else {
            list = head;
        }
        return list;
    }
};
