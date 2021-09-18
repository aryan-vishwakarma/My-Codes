#include <stdio.h>
int top = -1;
int n = 40;
int stack[40];
void push()
{
    if (top >= n - 1)
    {
        printf("STACK is OVERFLOW\n");
        getch();
    }
    else
    {
        printf("Enter a value to be pushed:\n");
        scanf("%d", &stack[++top]);
    }
}
void pop()
{
    if (top <= -1)
        printf("STACK is UNDERFLOW\n");
    else
        printf("Popped element is %d\n", stack[top--]);
}
void display()
{
    if (top <= -1)
        printf("Stack is EMPTY\n");
    else
    {
        printf("The elements of stack are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d  ", stack[i]);
        printf("\n");
    }
}
int main()
{
    int p;
    printf("Enter the choice\n1. push an element\n2. pop an element\n3. display the stack\n4. exit\n");
    while (1)
    {
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exited...");
            break;
        default:
            printf("INVALID INPUT TRY AGAIN\n");
        }
        if (p != 4)
            printf("Enter next choice:\n");
        else
            break;
    }
}