#include<stdio.h>
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n],i,odd[n],even[n],o=0,e=0;
    printf("Enter %d numbers: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        if(arr[i]&1)
        {
            even[e]=arr[i];
            e++;
        }
        else
        {
            odd[o]=arr[i];
            o++;
        }
    }
    if(o!=0)
    {
        printf("Odd numbers: ");
        for(i=0;i<o;i++)
        printf("%d ",odd[i]);
    }
    else printf("No odd numbers");
    printf("\n");
    if(e!=0)
    {
        printf("Even numbers: ");
        for(i=0;i<e;i++)
        printf("%d ",even[i]);
    }
    else printf("No even numbers");
}