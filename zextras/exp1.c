#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    int roll;
};
void main(){
    struct student *s;
    int i,j,n;
    printf("Enter n: ");
    scanf("%d",&n);
    s=(struct student*)malloc(n*sizeof(struct student));
    for(i=0;i<n;i++){
        printf("Enter name of student no. %d: ",i+1);
        scanf("%s",s[i].name);
        printf("Enter rollnumber of student no. %d: ",i+1);
        scanf("%d",&s[i].roll);
    }
    for(i=0;i<n;i++){
        printf("Name of student no. %d is %s\n",i+1,s[i].name);
        printf("Roll number of student no. %d is %d\n",i+1,s[i].roll);
    }
}