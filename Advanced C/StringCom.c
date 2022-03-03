#include<stdio.h>

int string_com(char* a, char* b) {
    while (*a == *b) {
        if (*a == '\0' || *b == '\0') {
            break;
        }
        
        a++;
        b++;
    }
    if (*a == '\0' && *b == '\0') {
        return 0;
    }
    if (*a == '\0') {
        return -1;
    }
    if (*b == '\0') {
        return 1;
    }
    if (*a > *b) {
        return 1;
    }
    else {
        return -1;
    }
}
int main() {
    char a[30], b[30];
    printf("Enter string a : ");
    gets(a);
    printf("Enter string b : ");
    gets(b);
    int res = string_com(a, b);
    if (res == 0) {
        printf("Strings are equal\n");
    }
    else if (res == -1) {
        printf("First string is less than Second string\n");
    }
    else {
        printf("First string is greater than First string\n");
    }
}