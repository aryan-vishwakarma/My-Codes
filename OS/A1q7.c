#include <stdio.h>
int main() {
    int n1, n2, n3;
    printf("Enter three numbers:\n");
    scanf("%d%d%d", &n1, &n2, &n3);
    int g = 0;
    if (n1 >= n2) {
        if (n1 >= n3) {
            g = n1;
        }
        else {
            g = n3;
        }
    }
    else {
        if (n2 >= n3) {
            g = n2;
        }
        else {
            g = n3;
        }
    }
    printf("%d is the maximum\n", g);
    return 0;
}