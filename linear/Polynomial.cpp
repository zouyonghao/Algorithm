#include <stdio.h>

struct ListNode {
    int val;
    int n;
    ListNode *next;
};

int main() {
    int n;
    scanf("%d", &n);
    while (n-- > 0) {
        // list 1
        ListNode *list1 = NULL;
        int a, b;
        scanf("%d %d", &a, &b);
        while (b >= 0) {
            ListNode *e = new ListNode;
            e->val = a;
            e->n = b;
            ListNode *tmp = list1;
            bool flag = false;
            while (tmp) {
                if (tmp->n == e->n) {
                    tmp->val += e->val;
                    flag = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (!flag) {
                e->next = list1;
                list1 = e;
            }
            scanf("%d %d", &a, &b);
        }
        // list2 + list1
        scanf("%d %d", &a, &b);
        while (b >= 0) {
            ListNode *e = new ListNode;
            e->val = a;
            e->n = b;
            ListNode *tmp = list1;
            bool flag = false;
            while (tmp) {
                if (tmp->n == e->n) {
                    tmp->val += e->val;
                    flag = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (!flag) {
                e->next = list1;
                list1 = e;
            }
            scanf("%d %d", &a, &b);
        }
        int lastMax = -1;
        while (true) {
            bool flag = false;
            ListNode *tmp = list1;
            int max = -1;
            int val;
            while (tmp) {
                if (tmp->n > max && (tmp->n < lastMax || lastMax < 0)) {
                    max = tmp->n;
                    val = tmp->val;
                    flag = true;
                }
                tmp = tmp->next;
            }
            if (flag) {
                lastMax = max;
                if (val != 0)
                    printf("[ %d %d ] ", val, max);
            } else {
                break;
            }
        }
        printf("\n");
    }
}