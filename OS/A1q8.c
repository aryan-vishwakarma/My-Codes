#include<stdio.h>
int main(){
    int n1, n2, f=0;
    float res;
    char op;
    printf("Enter the expression seperated by space:\n");
    scanf("%d %c %d", &n1, &op, &n2);
    switch (op){
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1*n2;
            break;
        case '/':
            res = n1/(float)n2;
            break;
        default:
            f=1;
            printf("Invalid Input\n");
            break;
    }
    if(f==0){
        printf("Result is : %0.3f", res);
    }
    return 0;
}