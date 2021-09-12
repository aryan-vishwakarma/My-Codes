#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL;
void create(){
    char ch;
    struct node *new_node,*current;
    do{
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(start==NULL)
        {
            start=new_node;
            current=new_node;
        }
        else{
            current->next=new_node;
            current=new_node;
        }printf("\nDo you want to create another : ");
        ch=getche();
    }while(ch!='n');
}
void display(){
    struct node *new_node;
    printf("\nThe Linked List : \n");
    new_node=start;
    printf("%d--->",new_node->data);
    while(new_node->next!=NULL){
        new_node=new_node->next;
        printf("%d--->",new_node->data);
    }
    printf("NULL\n");
}
void main()
{
    create();
    display();
}