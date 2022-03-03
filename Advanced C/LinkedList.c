#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stddef.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
} *start = NULL;
//function to create a linked list
void create()
{
    char ch;
    struct node* new_node, * current;
    do
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        if (start == NULL)
        {
            start = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        printf("Do you want to create another node : ");
        ch = getche();
    } while (ch != 'n');
}
//function to display the linked list
void display()
{
    struct node* new_node;
    printf("\nThe Linked List : \n");
    new_node = start;
    if (new_node != NULL) {
        printf("%d--->", new_node->data);
        while (new_node->next != NULL)
        {
            new_node = new_node->next;
            printf("%d--->", new_node->data);
        }
    }
    printf("NULL\n");
}
//function to add an element to the linkedd list
void addAt()
{
    printf("\nEnter the position at which you want to insert the node.\n");
    printf("Enter 0 for start and 999 for end\n");
    int p;
    scanf("%d", &p);
    struct node* new_node = (struct node*)malloc(sizeof(struct node)), * current, * temp;
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    current = start;
    if (p != 999 && p != 0)
    {
        for (int i = 0; i < p - 1; i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = new_node;
        new_node->next = temp;
    }
    else if (p == 0)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}
//function to delete an element from the linked list
void deleteAt()
{
    printf("\nEnter the position of the node you want to delete\n");
    printf("Enter 0 for start and 999 for end\n");
    int p;
    struct node* current;
    current = start;
    scanf("%d", &p);
    if (p == 0)
        start = start->next;
    else if (p == 999)
    {
        while (current->next->next != NULL)
            current = current->next;
        current->next = NULL;
    }
    else
    {
        for (int i = 0; i < p - 1; i++)
            current = current->next;
        current->next = current->next->next;
    }
}

void deleteBySearch() {
    int val;
    printf("\nEnter value to be deleted : ");
    scanf("%d", &val);
    struct node* cur, * prev;
    cur = start;
    prev = NULL;
    if (cur == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    while (cur != NULL) {
        if (cur->data == val) {
            if (prev == NULL) {
                start = cur->next;
                free(cur);
                return;
            }
            prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Cannot find %d\n", val);
}

//the main function
int main()
{
    create();
    display();
    int ch;
    printf("\nDo you want to add any node: ");
    ch = getche();
    while (ch != 'n')
    {
        addAt();
        display();
        printf("\nDo you want to add any other node: ");
        ch = getche();
    }
    printf("\nDo you want to delete any node: ");
    ch = getche();
    while (ch != 'n')
    {
        // deleteAt();
        deleteBySearch();
        display();
        printf("\nDo you want to delete any other node: ");
        ch = getche();
    }
    printf("\nExited...");
}