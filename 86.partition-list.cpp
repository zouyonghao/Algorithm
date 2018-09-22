/*
 * [86] Partition List
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (40.40%)
 * Total Accepted:    2.1K
 * Total Submissions: 5.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !(head->next)) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        while (pre->next != nullptr && pre->next->val < x) {
            pre = pre->next;
        }
        if (pre->next == head) head = pre;
        if (pre->next == nullptr) return head;
        ListNode* xNode = pre->next;
        ListNode* tmp = xNode;
        while (tmp->next) {
            if (tmp->next->val < x) {
                ListNode* needDeleted = tmp->next;
                tmp->next = tmp->next->next;
                pre->next = needDeleted;
                needDeleted->next = xNode;
                pre = pre->next;
            } else
                tmp = tmp->next;
        }
        return head->val == -1 ? head->next : head;
    }
};
