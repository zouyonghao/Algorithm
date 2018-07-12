#include <stdio.h>
// 设有n个顺序放置的足球，每个球表面标有A、B、C其中一个字母

// 要求:
// 重新摆放这些足球
// 使得所有表面为A的足球在前，所有表面为B的足球居中，所有表面为C的足球居后
// 重新摆放时对每个足球的字母只能看一次，并且只允许交换操作来调整足球的位置

// struct soccer{
//     char surface;
// };

// struct soccer {
//     char surface;
// };
// 请写明算法思想和时间复杂度，谢谢。

int main() {
    int n;
    scanf("%d", &n);
    char *array = new char[n];
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", array + i);
    }
    int aPtr = -1;
    int cPtr = n;
    for (int i = 0; i < n; i++) {
        if (array[i] == 'A' && i > aPtr) {
            aPtr++;
            char tmp = array[aPtr];
            array[aPtr] = array[i];
            array[i] = tmp;
            i--;
        } else if (array[i] == 'C' && i < cPtr) {
            cPtr--;
            char tmp = array[cPtr];
            array[cPtr] = array[i];
            array[i] = tmp;
            i--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%c ", array[i]);
    }
    return 0;
}

// 思路与快速排序类似，将整个数组划分成三块，
// 左侧是A，中间是B，右边是C
// 设置两个指针，指向左侧边界和右侧边界
// 扫面数组，遇到A则将左侧指针右移，并与当前指针交换内容
// 遇到C将右侧指针左移并交换内容
// 复杂度：与快速排序类似，介于O(n)到O(n^2)之间