#include<stdio.h>
struct node{
    int data;
    struct node *left,*right;
}*root=NULL;
void insertToBST(int n,struct node **node){
    if((*node)==NULL){
        (*node)=(struct node*)malloc(sizeof(struct node));
        (*node)->data=n;
        (*node)->left=NULL;
        (*node)->right=NULL;
    }
    else if(n>(*node)->data)
    insertToBST(n,&((*node)->right));
    else if(n<(*node)->data)
    insertToBST(n,&((*node)->left));
}
int findAndDeleteGreatest(struct node **node){
    int t;
    if((*node)->left==NULL&&(*node)->right==NULL){
        t=(*node)->data;
        (*node)=NULL;
    }
    else if((*node)->right==NULL){
        t=(*node)->data;
        (*node)=(*node)->left;
    }
    else{
        t=findAndDeleteGreatest(&((*node)->right));
    }
    return(t);
}
void deleteFromBST(int n,struct node **node){
    if((*node)==NULL){
        printf("Can't find %d\n",n);
    }
    else if((*node)->data==n){
        if((*node)->left==NULL&&(*node)->right==NULL){
            (*node)=NULL;
        }
        else if((*node)->left==NULL){
            (*node)=(*node)->right;
        }
        else if((*node)->right==NULL){
            (*node)=(*node)->left;
        }
        else{
            (*node)->data=findAndDeleteGreatest(&((*node)->left));
        }
    }
    else if((*node)->data>n)
    deleteFromBST(n,&((*node)->left));
    else
    deleteFromBST(n,&((*node)->right));
}
void inorderTraversal(struct node *node){  
    if(node!=NULL){
        inorderTraversal(node->left);
        printf("%d ",node->data);
        inorderTraversal(node->right);
    }
}
void preorderTraversal(struct node *node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}
void postorderTraversal(struct node *node){
    if(node!=NULL){
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ",node->data);
    }
}
int main(){
    printf("Enter n: ");
    int n;
    int t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        insertToBST(t,&root);
    }
    int ch;
    printf("Enter\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Show preorder transversal\n");
    printf("4. Show Inorder transversal\n");
    printf("5. Show postorder transversal\n");
    printf("6. Exit...\n");
    scanf("%d",&ch);
    while(ch!=6){
        switch(ch){
            case 1:
            scanf("%d",&t);
            insertToBST(t,&root);
            break;
            case 2:
            printf("Which element do you want to delete: ");
            scanf("%d",&t);
            deleteFromBST(t,&root);
            break;
            case 3:
            preorderTraversal(root);
            printf("\n");
            break;
            case 4:
            inorderTraversal(root);
            printf("\n");
            break;
            case 5:
            postorderTraversal(root);
            printf("\n");
            break;
            default:
            printf("Invalid Input\n");
        }
        printf("Enter next choice: ");
        scanf("%d",&ch);
    }
}