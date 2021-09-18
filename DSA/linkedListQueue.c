#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stddef.h>
struct queue
{
    int data;
    struct queue *next;
} *rear = NULL, *front = NULL;
void insertElement()
{
    struct queue *new_node;
    new_node = (struct queue *)malloc(sizeof(struct queue));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (rear == NULL)
    {
        rear = new_node;
        front = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}
void deleteElement()
{
    if (front == NULL)
        printf("Queue Underflow\n");
    else
    {
        printf("The deleted element is %d\n", front->data);
        front = front->next;
    }
}
void displayQueue()
{
    struct queue *new_node;
    new_node = front;
    printf("The Queue is:\n");
    printf("%d  ", new_node->data);
    while (new_node->next != NULL)
    {
        new_node = new_node->next;
        printf("%d  ", new_node->data);
    }
    printf("\n");
}
int main()
{
    int p;
    printf("Enter a choice:\n");
    printf("1.Insert an element\n2.Delete an element\n3.Display the Queue\n4.Exit\n");
    scanf("%d", &p);
    while (1)
    {
        switch (p)
        {
        case 1:
            insertElement();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            displayQueue();
            break;
        case 4:
            printf("Exited...\n");
            break;
        default:
            printf("INVALID INPUT, TRY AGAIN\n");
        }
        if (p != 4)
        {
            printf("Enter next choice: ");
            scanf("%d", &p);
        }
        else
            break;
    }
    return 0;
}