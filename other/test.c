#include "stdio.h"

int main()
{
    int *T;

    T = (int *)"\01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    if (*T == 1)
        printf("This machine is high-endian.\n");
    else
        printf("This machine is low-endian.\n");
}
