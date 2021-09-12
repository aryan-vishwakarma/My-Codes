#include<stdio.h>
void bubbleSort(int *a,int n){
    int i,j,t;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
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
    bubbleSort(a,n);
    printf("Array is sorted.\n");
    displayArr(a,n);
    return 0;
}