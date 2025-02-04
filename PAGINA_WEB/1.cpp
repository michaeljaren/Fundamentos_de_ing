#include <stdio.h>
int i, j, x = 0;
void main() {
    for (i = 0; i <= 5; i++) {
        for (j = 0; j < 5; j++) {
            switch (i - j - 1) {
                case -1:
                case 0: {
                    x = x + 1;
                    break;
                }
                case 1:
                case 2:
                case 3: {
                    x = x + 2;
                    break;
                }
                default:
                    x = x + 3;
            }
        }
    }
    printf("%d\n", x);
}
