/*
 * [234] Palindrome Linked List
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (32.64%)
 * Total Accepted:    7K
 * Total Submissions: 21.6K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(head != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head->next) return true;
        ListNode* pfast = head, *pslow = head;
        while(pfast && pfast->next) {
            pslow = pslow->next;
            pfast = pfast->next->next;
        }
        if (pfast) {
            pslow->next = reverse(pslow->next);
            pslow = pslow->next;
        } else {
            pslow = reverse(pslow);
        }
        while (pslow) {
            if (head->val != pslow->val) {
                return false;
            }
            head = head->next;
            pslow = pslow->next;
        }
        return true;
    }
};
