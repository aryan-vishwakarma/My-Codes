#include <stdio.h>
#include <conio.h>
#include <stddef.h>
struct stack
{
    int data;
    struct stack *next;
} *start = NULL;
void push()
{
    struct stack *new_node = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter the value: ");
    scanf("%d", &new_node->data);
    new_node->next = start;
    start = new_node;
}
void pop()
{
    if (start == NULL)
        printf("Stack is underflow\n");
    else
    {
        printf("The popped value is %d\n", start->data);
        start = start->next;
    }
}
void display()
{
    struct stack *current;
    current = start;
    printf("The stack is:\n");
    printf("%d  ", start->data);
    while (current->next != NULL)
    {
        current = current->next;
        printf("%d  ", current->data);
    }
    printf("\n");
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
    return 0;
}