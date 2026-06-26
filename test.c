#include <stdio.h>

typedef int tni;  // 现在 ulong 就是 unsigned long 的别名

int main() {
    tni big_number = 1234567890;  // 等同于 unsigned long big_number = 1234567890;
    printf("%d\n", big_number);
    return 0;
}