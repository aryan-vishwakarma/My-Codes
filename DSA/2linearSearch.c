#include<stdio.h>
void inputArr(int *a,int n){
    printf("Enter %d values:\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}
int linearSearch(int *a,int n,int k){
    for(int i=0;i<n;i++){
        if(a[i]==k)
        return i;
    }
    return -1;
}
int main(){
    int n,k;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    inputArr(a,n);
    printf("\nEnter the value to be searched: ");
    scanf("%d",&k);
    int p=linearSearch(a,n,k);
    if(p==-1)
    printf("\n%d not found in the Array.\n",k);
    else
    printf("\n%d found at index: %d\n",k,p);
}