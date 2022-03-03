#include<stdio.h>

int main() {
    int n;
    int* a;
    printf("Enter n : ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    printf("\nInitial values stroed are\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", *(a + i));
    }
    printf("\n\nEnter %d elements\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    printf("\nThe numbers and their addresses are\n");
    for (int i = 0; i < n; i++) {
        printf("%d  %d\n", *(a + i), (a + i));
    }
    free(a);
    return 0;
}