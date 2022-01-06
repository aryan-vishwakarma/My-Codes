#include<stdio.h>

int checkSorted(int* a, int n) {
    int f = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            f++;
        }
    }
    return f;
}

void bubbleSortModified(int* a, int n) {
    int count = 0;
    if (!checkSorted) {
        return;
    }
    int i, j, t;
    for (i = 0; i < n - 1; i++){
        if (checkSorted(a + i, n - i)) {
            for (j = 0; j < n - i - 1; j++) {
                count++;
                if (a[j] > a[j + 1]) {
                    t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
            }
        }
        else {
            break;
        }
    }
    printf("If checked %d times\n", count);
}

void inputArr(int* a, int n) {
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}

void displayArr(int* a, int n) {
    printf("The Array is\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, a[100];
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    inputArr(a, n);
    displayArr(a, n);
    printf("No. of placed where order is wrong is : %d\n", checkSorted(a, n));
    bubbleSortModified(a, n);
    displayArr(a, n);
    return 0;
}