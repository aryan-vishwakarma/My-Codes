#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,s=0;
    printf("Enter n: ");
    scanf("%d",&n);
    int *p;
    p=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter no.: ");
        scanf("%d",(p+i));
    }
    for(i=0;i<n;i++){
        s+=*(p+1);
    }
    printf("The sum is %d\n",s);
    p=(int*)realloc(p,(n+2)*sizeof(int));
    printf("Enter two more numbers: ");
    scanf("%d %d",(p+n),(p+n+1));
    s+=*(p+n)+*(p+n+1);
    printf("The new sum is %d",s);
}