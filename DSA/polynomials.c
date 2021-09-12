#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int pow;
    struct poly *next;
};
void inputPoly(struct poly*);
void addPoly(struct poly*,struct poly*,struct poly*);
void subtractPoly(struct poly*,struct poly*,struct poly*);
void removeDuplicates(struct poly*);
void multiplyPoly(struct poly*,struct poly*,struct poly*);
void printPoly(struct poly* ptr);

void inputPoly(struct poly *p){
    int n;
    printf("Enter the degree of polynomial: ");
    scanf("%d",&n);
    for(;n>=0;n--){
        printf("Enter the coefficient of x^%d: ",n);
        scanf("%d",&p->coeff);
        p->pow=n;
        p->next=(struct poly*)malloc(sizeof(struct poly));
        p=p->next;
        p->next=NULL;
    }
}
void addPoly(struct poly *poly1,struct poly *poly2,struct poly *sum){
    struct poly *sum1=sum;
    while(poly1->next!=NULL&&poly2->next!=NULL){
        if(poly1->pow>poly2->pow){
            sum1->pow=poly1->pow;
            sum1->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow){
            sum1->pow=poly2->pow;
            sum1->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        else{
            sum1->pow=poly1->pow;
            sum1->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        sum1->next=(struct poly *)malloc(sizeof(struct poly));
        sum1=sum1->next;
        sum1->next=NULL;
    }
    while(poly1->next||poly2->next){
        if(poly1->next){
            sum1->pow=poly1->pow;
            sum1->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next){
            sum1->pow=poly2->pow;
            sum1->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        sum1->next=(struct poly*)malloc(sizeof(struct poly));
        sum1=sum1->next;
        sum1->next=NULL;
    }
}
void subtractPoly(struct poly *poly1,struct poly *poly2,struct poly *diff){
    struct poly *diff1;
    diff1=diff;
    while(poly1->next&&poly2->next){
        if(poly1->pow>poly2->pow){
            diff1->pow=poly1->pow;
            diff1->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow){
            diff1->pow=poly2->pow;
            diff1->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        else{
            diff1->pow=poly1->pow;
            diff1->coeff=poly1->coeff-poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        diff1->next=(struct poly *)malloc(sizeof(struct poly));
        diff1=diff1->next;
        diff1->next=NULL;
    }
    while(poly1->next||poly2->next){
        if(poly1->next){
            diff1->pow=poly1->pow;
            diff1->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next){
            diff1->pow=poly2->pow;
            diff1->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        diff1->next=(struct poly*)malloc(sizeof(struct poly));
        diff1=diff1->next;
        diff1->next=NULL;
    }
}
void removeDuplicates(struct poly* start){
    struct poly *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->pow == ptr2->next->pow) {
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void multiplyPoly(struct poly* poly1,struct poly* poly2,struct poly *poly){
    struct poly *ptr1, *ptr2,*poly3;
    ptr1 = poly1;
    ptr2 = poly2;
    poly3=poly;
    while (ptr1->next != NULL) {
        while (ptr2->next != NULL){
            poly3->coeff = ptr1->coeff * ptr2->coeff;
            poly3->pow = ptr1->pow + ptr2->pow;
            ptr2 = ptr2->next;
            poly3->next=(struct poly*)malloc(sizeof(struct poly));
            poly3=poly3->next;
            poly3->next=NULL;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    removeDuplicates(poly);
}
void printPoly(struct poly* ptr){
    while (ptr->next->next != NULL) {
        printf("%dx^%d ",ptr->coeff,ptr->pow);
        if( ptr->next!=NULL && ptr->next->coeff >=0){
            if(ptr->next->coeff>=0)
            printf("+ ");
        }
        ptr = ptr->next;
    }
    printf("%d\n",ptr->coeff);
}
int main(){
    struct poly *poly1,*poly2,*ptr1,*ptr2;
    poly1=(struct poly*)malloc(sizeof(struct poly));
    poly2=(struct poly*)malloc(sizeof(struct poly));
    ptr1=poly1;
    ptr2=poly2;
    inputPoly(ptr1);
    inputPoly(ptr2);
    printf("First polynomial:\n");
    printPoly(poly1);
    printf("Second polynomial:\n");
    printPoly(poly2);
    printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication:\n");
    int ch;
    scanf("%d",&ch);
    struct poly *result=NULL;
    result=(struct poly*)malloc(sizeof(struct poly));
    result->next=NULL;
    switch (ch)
    {
        case 1:
        addPoly(poly1,poly2,result);
        break;
        case 2:
        subtractPoly(poly1,poly2,result);
        break;
        case 3:
        multiplyPoly(poly1,poly2,result);
        break;
        default:
        printf("INVALID INPUT\n");
        break;
    }
    if(ch==1||ch==2||ch==3){
        printf("\nThe result is:\n");
        printPoly(result);
    }
}