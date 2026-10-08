#include <stdio.h>

int main() {
    int i = 119;
    if (i <= 30) {
        printf("免費\n");
    } else if (i >= 240) {
        printf("240元\n");
    } else {
        int h = (i / 30);
        if (i % 30 != 0) {
            h = (i / 30) + 1;
        }
        int cost = h * 30;
        if (cost > 240) {
            cost = 240;
        }
        printf("%d元\n", cost);
    }
    return 0;
}
