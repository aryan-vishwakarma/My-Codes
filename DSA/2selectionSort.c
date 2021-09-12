#include<stdio.h>
void selectionSort(int *a,int n){
    int i,j,t,maxPos;
    for(int i=0;i<n-1;i++){
        maxPos=0;
        for(j=1;j<n-i;j++)
        if(a[j]>a[maxPos])
        maxPos=j;
        t=a[maxPos];
        a[maxPos]=a[n-i-1];
        a[n-i-1]=t;
    }
}
void inputArr(int *a,int n){
    printf("Enter %d values:\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}
void displayArr(int *a,int n){
    printf("The array is:\n");
    for(int i=0;i<n;i++)
    printf("%d  ",a[i]);
    printf("\n");
}
int main()
{
    printf("Enter the value of n: ");
    int n;
    scanf("%d",&n);
    int a[n];
    inputArr(a,n);
    displayArr(a,n);
    selectionSort(a,n);
    printf("Array is sorted.\n");
    displayArr(a,n);
    return 0;
}