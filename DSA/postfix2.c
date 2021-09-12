#include <stdio.h>
#include <ctype.h>
float stack[20];
int top = -1;
void push(float x){
    stack[++top] = x;
}
float pop(){
    return stack[top--];
}
int main(){
    char exp[100];
    char *e;
    float x,y;
    printf("Enter the postfix expression :\n");
    scanf("%s", exp);
    e = exp;
    while(*e!='\0'){
        if(isdigit(*e))
        push((float)(*e)-48.0);
        else{
            y=pop();
            x=pop();
            switch(*e){
                case '+':
                push(x+y);
                break;
                case '-':
                push(x-y);
                break;
                case '*':
                push(x*y);
                break;
                case '/':
                push(x/y);
                break;
            }
        }
        e++;
    }
    printf("The solution is:\n%f",stack[top]);
}