#include<stdio.h>

typedef struct {
    char name[50];
    long long int acc_no;
    float balance;
}Customer;

int main() {
    int n;
    printf("Enter no. of customers : ");
    scanf("%d", &n);
    Customer customer[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for customer %d\n");
        printf("Enter name : ");
        fflush(stdin);
        scanf("%[^\n]s", customer[i].name);
        printf("Enter account number : ");
        scanf("%lld", &customer[i].acc_no);
        printf("Enter balance amount in $ : ");
        scanf("%f", &customer[i].balance);
    }

    printf("\nCustomers having balance less than $200:\n");
    for (int i = 0; i < n; i++) {
        if (customer[i].balance < 200) {
            printf("\t%s\n", customer[i].name);
        }
    }

    printf("\nUpdated balance of customers having balance more than $1000:\n");
    for (int i = 0; i < n; i++) {
        if (customer[i].balance > 1000) {
            printf("Name : %s\n", customer[i].name);
            printf("\tPrevious balance : %f\n", customer[i].balance);
            customer[i].balance += 100;
            printf("\tUpdated balance : %f\n\n", customer[i].balance);
        }
    }
}