/*
 * [141] Linked List Cycle
 *
 * https://leetcode-cn.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (29.77%)
 * Total Accepted:    7.2K
 * Total Submissions: 24.3K
 * Testcase Example:  '[]\nno cycle'
 *
 * 给定一个链表，判断链表中是否有环。
 * 
 * 进阶：
 * 你能否不使用额外空间解决此题？
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };值得注意，又是快慢指针的问题
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)return true;
        }
        return false;
    }
};

