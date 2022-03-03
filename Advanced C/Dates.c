#include<stdio.h>
#include<stdbool.h>
typedef struct {
    int day, month, year;
}Date;

bool isEqualDate(Date d1, Date d2) {
    if (d1.day == d2.day&&
        d1.month == d2.month&&
        d1.year == d2.year) {
        return true;
    }
    return false;
}

int main() {
    Date d1, d2;
    printf("For 1st date\n\tEnter day : ");
    scanf("%d", &d1.day);
    printf("\tEnter month : ");
    scanf("%d", &d1.month);
    printf("\tEnter year : ");
    scanf("%d", &d1.year);
    printf("For 2nd date\n\tEnter day : ");
    scanf("%d", &d2.day);
    printf("\tEnter month : ");
    scanf("%d", &d2.month);
    printf("\tEnter year : ");
    scanf("%d", &d2.year);

    if (isEqualDate(d1, d2)) {
        printf("\nDates are equal\n");
    }
    else {
        printf("\nDates are not equal\n");
    }
}