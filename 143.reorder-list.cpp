/*
 * [143] Reorder List
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (43.08%)
 * Total Accepted:    1.3K
 * Total Submissions: 3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    // trival solution
    // void reorderList(ListNode* head) {
    //     if (!head) return;
    //     while (head->next) {
    //         // cout << head->val << endl;
    //         ListNode* tailPre = head;
    //         ListNode* tail = head->next;
    //         while (tail->next) {
    //             tailPre = tail;
    //             tail = tail->next;
    //         }
    //         if (head != tailPre) {
    //             ListNode* tmp = head->next;
    //             tailPre->next = nullptr;
    //             head->next = tail;
    //             tail->next = tmp;
    //             head = tmp;
    //         } else {
    //             return;
    //         }
    //     }
    // }

    // better solution
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // find mid node
        ListNode* pre = head;
        ListNode* lat = head->next;
        while (lat && lat->next) {
            pre = pre->next;
            lat = lat->next->next;
        }

        // reverse list after mid (sublist)
        ListNode* p = pre->next;
        pre->next = nullptr;
        ListNode* subhead = nullptr;
        while (p) {
            ListNode* tmp = p->next;
            p->next = subhead;
            subhead = p;
            p = tmp;
        }

        // insert sublist to original list one by one
        while (head && subhead) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = subhead->next;
            head->next = subhead;
            subhead->next = tmp1;
            head = tmp1;
            subhead = tmp2;
        }

    }
};
