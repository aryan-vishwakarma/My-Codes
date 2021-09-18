#include <stdio.h>
struct student
{
    int marks;
};
int main()
{
    struct student s[5];
    char name[20];
    int total = 0;
    printf("Enter the name of the student: ");
    gets(name);
    for (int i = 0; i < 5; i++)
    {
        printf("Enter marks of subject %d :", i + 1);
        scanf("%d", &s[i].marks);
    }
    for (int i = 0; i < 5; i++)
    {
        total += s[i].marks;
    }
    printf("Name: %s\n", name);
    for (int i = 0; i < 5; i++)
        printf("Marks in subject %d: %d\n", i + 1, s[i].marks);
    printf("Total marks: %d\n", total);
    return 0;
}