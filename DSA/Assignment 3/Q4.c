#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
struct node{
    char data[5];
    struct node *left,*right;
}*root=NULL;
int Priority(char ch){
    if(ch=='-'||ch=='+')
    return 0;
    if(ch=='*'||ch=='/')
    return 1;
    if(ch=='^')
    return 2;
    return;
}
int find_min_pri(char str[50]){
    int l=strlen(str),i;
    char st[50];
    int minPos=-1;
    int minVal=10;
    int pri;
    if(str[0]=='('&&str[l-1]==')'){
        for(i=1;i<l-1;i++){
            st[i-1]=str[i];
        }
        st[i]='\0';
        str[0]='\0';
        strcpy(str,st);
    }
    int open_bracket=0;
    int closed_bracket=0;
    for(i=0;i<l;i++){
        if(str[i]=='(')
        open_bracket++;
        else if(str[i]==')')
        closed_bracket++;
        else if(open_bracket==closed_bracket){
            pri=Priority(str[i]);
            if(pri<minVal){
                minPos=i;
                minVal=pri;
            }
        }
    }
    return minPos;
}
void infix_to_tree(struct node **node,char str[50]){
    int pos=find_min_pri(str);
    *node=(struct node*)malloc(sizeof(struct node));
    (*node)->left=NULL;
    (*node)->right=NULL;
    if(pos==-1)
    strcpy((*node)->data,str);
    else{
        int i;
        char strleft[50];
        char strright[50];
        for(i=0;i<pos;i++){
            strleft[i]=str[i];
        }
        strleft[i]='\0';
        (*node)->data[0]=str[pos];
        (*node)->data[1]='\0';
        for(i=pos+1;i<strlen(str);i++){
            strright[i-pos-1]=str[i];
        }
        strright[i]='\0';
        infix_to_tree(&((*node)->left),strleft);
        infix_to_tree(&((*node)->right),strright);
    }
}
void infixExpression(struct node *node){  
    if(node!=NULL){
        if(node->left!=NULL&&Priority(node->data[0])>Priority(node->left->data[0])){
            printf("( ");
            infixExpression(node->left);
            printf(")");
        }
        else
        infixExpression(node->left);
        printf("%s ",node->data);
        if(node->right!=NULL&&Priority(node->data[0])>Priority(node->right->data[0])){
            printf("( ");
            infixExpression(node->right);
            printf(") ");
        }
        else
        infixExpression(node->right);
    }
}
void inorderTraversal(struct node *node){  
    if(node!=NULL){
        inorderTraversal(node->left);
        printf("%s ",node->data);
        inorderTraversal(node->right);
    }
}
void postorderTraversal(struct node *node){
    if(node!=NULL){
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%s ",node->data);
    }
}
int main(){
    char str[50];
    printf("Enter the expression\n");
    scanf("%s",str);
    infix_to_tree(&root,str);
    printf("Infix Expression:\n");
    infixExpression(root);
    printf("\n");
    printf("Postfix Expression:\n");
    postorderTraversal(root);
    printf("\n");
}