#include<stdio.h>
void multiply(float a[20][20],float b[20][20],int n,float ab[20][20])
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        ab[i][j]=0;
        for(int c=0;c<n;c++)
        ab[i][j]+=b[c][j]*a[i][c];
    }
}
void inputMat(float a[20][20],int n)
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%f",&a[i][j]);
}
void printMat(float a[20][20],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%.2f\t",a[i][j]);
        printf("\n");
    }
}
int main()
{
    printf("Enter n: ");
    int n;
    float a[20][20],b[20][20],ab[20][20];
    scanf("%d",&n);
    printf("Enter the elements in matrix A:\n");
    inputMat(a,n);
    printf("Enter the elements in matrix B:\n");
    inputMat(b,n);
    multiply(a,b,n,ab);
    printf("The matrix A*B is:\n");
    printMat(ab,n);
    return 0;
}