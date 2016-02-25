#include <iostream>

struct List {
    int value;
    List *next;
};

int main() {
    List head;
    head.value = -1;
    int n;
    std::cin >> n;
    List *tmp = &head;
    for (int i = 0; i < n; i++) {
        List *a = (List *) malloc(sizeof(List));
        a->value = i;
        a->next = NULL;
        tmp->next = a;
        tmp = tmp->next;
    }
    tmp = &head;
    while (tmp->next != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }

    tmp = &head;
    List *newNext = NULL;
    List *oldNext = tmp->next;
    while (oldNext != NULL) {
        tmp->next = newNext;
        newNext = tmp;
        tmp = oldNext;
        oldNext = oldNext->next;
    }
    
    tmp->next = newNext;
    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}