#include <stdio.h>
float doo(int p)
{
    float a, b;
    switch (p)
    {
    case 1:
        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);
        return (a + b);
        break;
    case 2:
        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);
        return (a - b);
        break;
    case 3:
        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);
        return (a * b);
        break;
    case 4:
        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);
        return (a / b);
        break;
    default:
        printf("Wrong Input\n");
    }
}
int main()
{
    printf("Enter\n1 for Addition\n2 for subtraction\n3 for multiplication\n4 for division\n5 for exit\n");
    int p;
    scanf("%d", &p);
    while (p != 5)
    {
        printf("%f\n", doo(p));
        printf("Enter\n1 for Addition\n2 for subtraction\n3 for multiplication\n4 for division\n5 for exit\n");
        scanf("%d", &p);
    }
    printf("Exited successfully!\n");
    return 0;
}