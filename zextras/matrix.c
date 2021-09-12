#include<stdio.h>
float deter(float a[20][20],int n)//applicable for 3*3 only
{
    int j,k;
    float s,p;
    for(int i=0;i<n;i++)
    {
        p=1;
        for(j=0;j<n;j++)
        {
            if(i+j<n)
            p*=a[i+j][j];
            else
            p*=a[i+j-n][j];
        }
        s+=p;
        p=1;k=0;
        for(j=n-1;j>=0;j--)
        {
            if(i+k<n)
            p*=a[i+k][j];
            else
            p*=a[i+k-n][j];
            k++;
        }
        s-=p;
    }
    return(s);
}
float deter2(float a[20][20],int n)//applicable for any
{
    if(n==1)
    return(a[0][0]);
    float a1[20][20],d=0.0;
    int i2,j2;
    for(int i=0;i<n;i++)
    {
        i2=0;j2=0;
        for(int i1=1;i1<n;i1++)
        {
            for(int j1=0;j1<n;j1++)
            {
                if(j1==i)continue;
                a1[i2][j2]=a[i1][j1];
                if(j2==n-2)
                {
                    j2=0;
                    i2++;
                }
                else
                j2++;
            }
        }
        if(i%2==0)
        d+=a[0][i]*deter2(a1,n-1);
        else
        d-=a[0][i]*deter2(a1,n-1);
    }
    return(d);
}
void main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    float a[20][20];
    printf("Enter %d numbers:\n",n*n);
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%f",&a[i][j]);
    printf("The determinant is: %f",deter2(a,n));
}