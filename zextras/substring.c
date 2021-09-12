#include<stdio.h>
#include<string.h>
int wwwwww(char s[])
{
    int l=strlen(s),wo=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]>=97)
        wo+=(s[i]-96)*(i+1);
        else
        wo+=(s[i]-64)*2*(i+1);
    }
    return(wo);
}
void printFactors(int n1,int n2)
{
    for(int i=1;i<=n1;i++)
    {
        if(n1%i==0&&n2%i==0)
        printf("%d ",i);
    }
}
int main()
{
    char S[30],s1[5];
    printf("enter a string: ");
    scanf("%s",S);
    int i,l=strlen(S),j,k,w,ww;
    ww=wwwwww(S);
    for(i=1;i<=l;i++)
    {
        for(j=0;j<l-i+1;j++)
        {
            char str[30]={'\0'};
            for(k=j;k<j+i;k++)
            {
                s1[0]=S[k];
                s1[1]='\0';
                strcat(str,s1);
               
            }
            printf("%s\n",str);
            w=wwwwww(str);
            printFactors(w,ww);
            printf("\n");
        }
    }
    return 0;
}