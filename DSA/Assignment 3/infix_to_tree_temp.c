#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
struct node
{
    char data[5];
    struct node *left, *right;
} *root = NULL;
int OPvalue(char ch)
{
    switch (ch)
    {
    case '-':
        return 0;
    case '+':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        return 10;
    }
}
int Priority(char ch)
{
    if (ch == '-' || ch == '+')
        return 0;
    if (ch == '*' || ch == '/')
        return 1;
    if (ch == '^')
        return 2;
    return;
}
int find_min_pri(char str[50])
{
    int l = strlen(str), i;
    char st[50];
    int minPos = -1;
    int minVal = 10;
    int op;
    if (str[0] == '(' && str[l - 1] == ')')
    {
        for (i = 1; i < l - 1; i++)
        {
            st[i - 1] = str[i];
        }
        st[i] = '\0';
        str[0] = '\0';
        strcpy(str, st);
    }
    int open_bracket = 0;
    int closed_bracket = 0;
    for (i = 0; i < l; i++)
    {
        if (str[i] == '(')
            open_bracket++;
        else if (str[i] == ')')
            closed_bracket++;
        else if (open_bracket == closed_bracket)
        {
            op = OPvalue(str[i]);
            if (op < minVal)
            {
                minPos = i;
                minVal = op;
            }
        }
    }
    return minPos;
}
void infix_to_tree(struct node **node, char str[50])
{
    int pos = find_min_pri(str);
    *node = (struct node *)malloc(sizeof(struct node));
    (*node)->left = NULL;
    (*node)->right = NULL;
    if (pos == -1)
        strcpy((*node)->data, str);
    else
    {
        int i;
        char strleft[50];
        char strright[50];
        for (i = 0; i < pos; i++)
        {
            strleft[i] = str[i];
        }
        strleft[i] = '\0';
        (*node)->data[0] = str[pos];
        (*node)->data[1] = '\0';
        for (i = pos + 1; i < strlen(str); i++)
        {
            strright[i - pos - 1] = str[i];
        }
        strright[i] = '\0';
        infix_to_tree(&((*node)->left), strleft);
        infix_to_tree(&((*node)->right), strright);
    }
}
void inorderTraversal(struct node *node)
{
    if (node != NULL)
    {
        if (node->left != NULL && Priority(node->data[0]) > Priority(node->left->data[0]))
        {
            printf("( ");
            inorderTraversal(node->left);
            printf(") ");
        }
        else
            inorderTraversal(node->left);
        printf("%s ", node->data);
        if (node->right != NULL && Priority(node->data[0]) > Priority(node->right->data[0]))
        {
            printf("( ");
            inorderTraversal(node->right);
            printf(") ");
        }
        else
            inorderTraversal(node->right);
    }
}
void preorderTraversal(struct node *node)
{
    if (node != NULL)
    {
        printf("%s ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}
void postorderTraversal(struct node *node)
{
    if (node != NULL)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%s ", node->data);
    }
}
bool isNum(char str[])
{
    bool f = true;
    int l = strlen(str);
    for (int i = 0; i < l; i++)
    {
        if (!isdigit(str[i]))
        {
            f = false;
            break;
        }
    }
    return f;
}
int solve(struct node *node)
{
    if (isNum(node->data))
    {
        return (atoi(node->data));
    }
    else
    {
        switch (node->data[0])
        {
        case '-':
            return (solve(node->left) - solve(node->right));
            break;
        case '+':
            return (solve(node->left) + solve(node->right));
            break;
        case '*':
            return (solve(node->left) * solve(node->right));
            break;
        case '/':
            return (solve(node->left) / solve(node->right));
            break;
        case '^':
            return (pow(solve(node->left), solve(node->right)));
            break;
        }
    }
}
int main()
{
    char str[50];
    printf("Enter the expression\n");
    scanf("%s", str);
    infix_to_tree(&root, str);
    printf("Inorder:\n");
    inorderTraversal(root);
    printf("\n");
    printf("Postorder:\n");
    postorderTraversal(root);
    printf("\n");
    printf("Preorder:\n");
    preorderTraversal(root);
    printf("\n");
    printf("Solution: %d", solve(root));
}