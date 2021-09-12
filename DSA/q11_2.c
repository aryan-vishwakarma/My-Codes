#include<stdio.h>
int fact(int n){
    if(n==0)
    return(1);
    if(n==1)
    return 1;
    return(n*fact(n-1));
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("The factorial of %d is %d",n,fact(n));
}