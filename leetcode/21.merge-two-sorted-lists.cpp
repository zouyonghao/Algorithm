/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (42.41%)
 * Total Accepted:    380.7K
 * Total Submissions: 897.1K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * merged = new ListNode(-1);
        ListNode * tmp = merged;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tmp->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        while(l1 != NULL) {
            tmp->next = new ListNode(l1->val);
            l1 = l1->next;
            tmp = tmp->next;
        }
        while(l2 != NULL) {
            tmp->next = new ListNode(l2->val);
            l2 = l2->next;
            tmp = tmp->next;
        }
        return merged->next;
    }
};
