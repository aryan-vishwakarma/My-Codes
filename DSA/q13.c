#include <stdio.h>
int n = 40, rear = -1, front = -1;
int queue[40];
void insertElement()
{
    if (rear <= n - 1)
    {
        if (front == -1)
            front = 0;
        printf("Enter the number to be inserted:\n");
        scanf("%d", &queue[++rear]);
    }
    else
        printf("Queue overflow occured\n");
}
void deleteElement()
{
    if (front == -1 || front >= rear)
        printf("Queue Underflow occured\n");
    else
        printf("Element deleted from the queue is %d\n", queue[front++]);
}
void displayQueue()
{
    if (front == -1 || front > rear)
        printf("No elements to display\n");
    else
    {
        printf("The elements of the queue are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }
}
void emptyQueue()
{
    front = -1;
    rear = -1;
    printf("Queue is emptied\n");
}
int main()
{
    int p;
    printf("Enter a choice:\n");
    printf("1.Insert an element\n2.Delete an element\n3.Display queue\n4.Empty Queue\n5.Exit\n");
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
            emptyQueue();
            break;
        case 5:
            printf("Exited...\n");
            break;
        default:
            printf("INVALID INPUT, TRY AGAIN\n");
        }
        if (p != 5)
        {
            printf("Enter next choice: ");
            scanf("%d", &p);
        }
        else
            break;
    }
}