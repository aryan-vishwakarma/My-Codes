#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
struct node{
    char data;
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
bool isOperand(char ch){
    if(ch=='-'||ch=='+'||ch=='*'||ch=='/'||ch=='^')
    return true;
    return false;
}
void postfix_to_tree(struct node **node,char str[50]){
    int l=strlen(str);
    if(!isOperand(str[l-1])){
        *node=(struct node*)malloc(sizeof(struct node));
        (*node)->data=str[l-1];
        (*node)->left=NULL;
        (*node)->right=NULL;
        str[l-1]='\0';
    }
    else{
        *node=(struct node*)malloc(sizeof(struct node));
        (*node)->data=str[l-1];
        (*node)->left=NULL;
        (*node)->right=NULL;
        str[l-1]='\0';
        l--;
        postfix_to_tree(&((*node)->right),str);
        str[l-1]='\0';
        postfix_to_tree(&((*node)->left),str);
    }
}
void inorderTraversal(struct node *node){  
    if(node!=NULL){
        if(node->left!=NULL&&Priority(node->data)>Priority(node->left->data)){
            printf("( ");
            inorderTraversal(node->left);
            printf(")");
        }
        else
        inorderTraversal(node->left);
        printf("%c ",node->data);
        if(node->right!=NULL&&Priority(node->data)>Priority(node->right->data)){
            printf("( ");
            inorderTraversal(node->right);
            printf(") ");
        }
        else
        inorderTraversal(node->right);
    }
}
int solve(struct node *node){
    if(isdigit(node->data)){
        return((node->data)-48);
    }
    else{
        switch(node->data){
            case '-':
            return(solve(node->left)-solve(node->right));
            break;
            case '+':
            return(solve(node->left)+solve(node->right));
            break;
            case '*':
            return(solve(node->left)*solve(node->right));
            break;
            case '/':
            return(solve(node->left)/solve(node->right));
            break;
            case '^':
            return(pow(solve(node->left),solve(node->right)));
            break;
        }
    }
}
int main(){
    char str[50];
    printf("Enter the expression\n");
    scanf("%s",str);
    postfix_to_tree(&root,str);
    printf("Inorder:\n");
    inorderTraversal(root);
    printf("\n");
    printf("Solution: %d",solve(root));
}