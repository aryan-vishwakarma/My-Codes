#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char code[8];
    char name[50];
    int credits;
}Course;

typedef struct {
    char name[50];
    char student_number[10];
    Course courses[20];
    int credits;
    int no_of_courses;
}Student;

void displayDetails(Student stu[], int n) {
    for (int i = 0; i < n; i++) {
        printf("For student %d\n", (i + 1));
        printf("\tName : %s\n", stu[i].name);
        printf("\tStudent number : %s\n", stu[i].student_number);
        printf("\tCourses :\n");
        for (int j = 0; j < stu[i].no_of_courses; j++) {
            printf("\t\tCode: %s, Name: %s, Credits: %d\n", stu[i].courses[j].code, stu[i].courses[j].name, stu[i].courses[j].credits);
        }
        printf("\tTotal Credits : %d\n\n", stu[i].credits);
    }
}
int searchStuNum(Student stu[], int n, char num[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stu[i].student_number, num) == 0) {
            return i;
        }
    }
    return -1;
}
int searchCourseCode(Student stu, int n, char code[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(stu.courses[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}
void withdraw(Student stu[], int n) {
    printf("Enter Student no. for which course is to be withdrawn : ");
    char st_num[10];
    scanf("%s", st_num);
    int k = searchStuNum(stu, n, st_num);
    if (k == -1) {
        printf("Cannot find student number\n");
        return;
    }
    printf("Enter course code which is to be withdrawn : ");
    char cr_code[7];
    scanf("%s", cr_code);
    int c = searchCourseCode(stu[k], n, cr_code);
    if (c == -1) {
        printf("Cannot find course code\n");
        return;
    }
    int cred = stu[k].courses[c].credits;
    for (int i = c; i < stu[k].no_of_courses - 1; i++) {
        stu[k].courses[i] = stu[k].courses[i + 1];
    }
    stu[k].no_of_courses--;
    stu[k].credits -= cred;
}
void addACourse(Student stu[], int n) {
    printf("Enter Student no. for which course is to be added : ");
    char st_num[10];
    scanf("%s", st_num);
    int k = searchStuNum(stu, n, st_num);
    if (k == -1) {
        printf("Cannot find student number\n");
        return;
    }
    if (stu[k].no_of_courses >= 20) {
        printf("Can not add more courses\n");
        return;
    }
    fflush(stdin);
    printf("Enter course code : ");
    scanf("%s", stu[k].courses[stu[k].no_of_courses].code);
    fflush(stdin);
    printf("Enter course name : ");
    scanf("%[^\n]s", stu[k].courses[stu[k].no_of_courses].name);
    printf("Enter no. of credits : ");
    scanf("%d", &stu[k].courses[stu[k].no_of_courses].credits);
    stu[k].credits += stu[k].courses[stu[k].no_of_courses].credits;
    stu[k].no_of_courses++;
}
int main() {
    int no_of_stu;
    char che;
    printf("Enter no. of students : ");
    scanf("%d", &no_of_stu);
    Student students[no_of_stu];
    for (int i = 0; i < no_of_stu; i++) {
        printf("For student %d\nEnter student number : ", (i + 1));
        scanf("%s", students[i].student_number);
        // getche();
        // char temp[2];
        // gets(temp);
        che = getchar();
        printf("Enter Name of student : ");
        scanf("%[^\n]s", students[i].name);
        printf("Enter no. of courses registered : ");
        scanf("%d", &students[i].no_of_courses);
        students[i].credits = 0;
        if (students[i].no_of_courses <= 20) {
            for (int j = 0; j < students[i].no_of_courses; j++) {
                fflush(stdin);
                printf("For course %d\nEnter Course code : ", (j + 1));
                scanf("%[^\n]s", students[i].courses[j].code);
                // printf("%s\n", students[i].courses[j].code);
                // getche();
                // gets(temp);
                // che = getchar();
                fflush(stdin);
                printf("Enter Course name : ");
                scanf("%[^\n]s", students[i].courses[j].name);
                // printf("%s\n%s", students[i].courses[j].code, students[i].courses[j].name);
                printf("Enter no. of credits : ");
                scanf("%d", &students[i].courses[j].credits);
                students[i].credits += students[i].courses[j].credits;
            }
        }
    }
    int ch = 1;
    while (ch != 4) {
        printf("\nEnter 1 for printing students' details\nEnter 2 to withdraw a course\nEnter 3 to add a course\nEnter 4 to exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            displayDetails(students, no_of_stu);
            break;
        case 2:
            withdraw(students, no_of_stu);
            break;
        case 3:
            addACourse(students, no_of_stu);
            break;
        }
    }
}