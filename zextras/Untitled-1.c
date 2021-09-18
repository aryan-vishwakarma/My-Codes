#include <stdio.h>
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
int main()
{
    int num1, num2, i = 0;
    char c;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    while (i < 1)
    {
        printf("choose'+' for addition , '-' for subtraction, '*' for multiplication, '/' for division, 'e' for ending the operation");
        scanf("%c", &c);
        if (c == '+')
        {
            printf("%d + %d = %d\n", num1, num2, add(num1, num2));
            i = i - 1;
        }
        else if (c == '-')
        {
            printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
            i = i - 1;
        }
        else if (c == '*')
        {
            printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
            i = i - 1;
        }
        else if (c == '/')
        {
            printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
            i = i - 1;
        }
        else if (c == 'e')
        {
            printf("operation ended");
            break;
        }
        else
            printf("Value of c is taken wrong.");
        printf("hello\n");
        printf("%d\n", i);
    }
    return 0;
}
int add(int n1, int n2)
{
    int result;
    result = n1 + n2;
    return result;
}
int subtract(int n1, int n2)
{
    int result;
    result = n1 - n2;
    return result;
}
int multiply(int n1, int n2)
{
    int result;
    result = n1 * n2;
    return result;
}
int divide(int n1, int n2)
{
    int result;
    result = n1 / n2;
    return result;
}