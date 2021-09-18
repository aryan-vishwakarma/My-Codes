#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20], s2[20];
    int i, f = 0;
    printf("Enter first string : ");
    scanf("%s", s1);
    printf("Enter second string : ");
    scanf("%s", s2);
    if (strlen(s1) == strlen(s2))
    {
        for (i = 0; i < strlen(s2); i++)
        {
            if (s1[i] != s2[i])
                f = 1;
        }
        if (f == 1)
            printf("\nStrings are not equal\n\n");
        else
            printf("\nStrings are equal\n\n");
    }
    else
    {
        printf("\nStrings are not equal\n\n");
    }
    if (strlen(s1) == 0)
        printf("First string is null.\n");
    else
        printf("First string is not null\n");
    if (strlen(s2) == 0)
        printf("Second string is null.\n\n");
    else
        printf("Second string is not null\n\n");
    f = 0;
    for (i = 0; i < strlen(s1); i++)
    {
        if (!(('0' <= s1[i] && s1[i] <= '9') || ('a' <= s1[i] && s1[i] <= 'z') || ('A' <= s1[i] && s1[i] <= 'Z')))
        {
            f = 1;
            break;
        }
    }
    if (f == 0)
        printf("First string does not contain special characters.\n");
    else
        printf("First string contains special character(s).\n");
    f = 0;
    for (i = 0; i < strlen(s2); i++)
    {
        if (!(('0' <= s2[i] && s2[i] <= '9') || ('a' <= s2[i] && s1[i] <= 'z') || ('A' <= s2[i] && s2[i] <= 'Z')))
        {
            f = 1;
            break;
        }
    }
    if (f == 0)
        printf("Second string does not contain special characters.\n\n");
    else
        printf("Second string contains special character(s).\n\n");
    return 0;
}