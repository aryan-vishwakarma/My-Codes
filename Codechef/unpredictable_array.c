#include<stdio.h>
#include<math.h>
int a[100000];
int n,k1,k2,i;
long int value;
void change(int x, int y){
    for(i=0;i<n;i++){
        if(a[i]==x)
        {
            k2=0;
            k1=0;
            if(i>0)
            k1=abs(a[i]-a[i-1]);
            if(i<n-1)
            k2=abs(a[i]-a[i+1]);
            a[i]=y;
            if(i>0)
            k1-=abs(a[i]-a[i-1]);
            if(i<n-1)
            k2-=abs(a[i]-a[i+1]);
            value-=k1+k2;
        }
    }
}
void val(){
    for(i=0;i<n-1;i++)
    value+=abs(a[i]-a[i+1]);
}
int main(){
    int t,q,j,x,y;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        printf("Case %d:\n",i+1);
        scanf("%d %d",&n,&q);
        //array input
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        val();
        for(j=0;j<q;j++){
            scanf("%d %d",&x,&y);
            change(x,y);
            printf("%ld\n",value);
        }
    }
}