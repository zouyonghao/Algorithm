/*
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (29.64%)
 * Total Accepted:    4.3K
 * Total Submissions: 14.4K
 * Testcase Example:  'No intersection: []\n[]'
 *
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 
 * 
 * 
 * 例如，下面的两个链表：
 * 
 * A:          a1 → a2
 * ⁠                  ↘
 * ⁠                    c1 → c2 → c3
 * ⁠                  ↗            
 * B:     b1 → b2 → b3
 * 
 * 
 * 在节点 c1 开始相交。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 * 
 * 
 * 
 * 
 * 致谢:
 * 特别感谢 @stellari 添加此问题并创建所有测试用例。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        ListNode* tmp = headA;
        while (tmp) {
            lengthA++;
            tmp = tmp->next;
        }
        tmp = headB;
        while (tmp) {
            lengthB++;
            tmp = tmp->next;
        }
        if (lengthA < 1 || lengthB < 1)
            return NULL;
        int length;
        if (lengthA > lengthB) {
            for (int i = 0; i < lengthA - lengthB; i++) {
                headA = headA->next;
            }
            length = lengthB;
        } else {
            for (int i = 0; i < lengthB - lengthA; i++) {
                headB = headB->next;
            }
        }
        for (int i = 0; i < length; i++) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
