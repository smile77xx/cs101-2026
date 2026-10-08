#include <stdio.h>

int main() {
    int i = 1599;
    if (i <= 1500) {
        printf("70元\n");
    } else {
        int n = i - 1500;
        int add = 0;
        if (n % 100 != 0) {
            add = ((n / 100) + 1) * 10;
        } else {
            add = (n / 100) * 10;
        }
        printf("%d元\n", 70 + add);
    }
    return 0;
}
