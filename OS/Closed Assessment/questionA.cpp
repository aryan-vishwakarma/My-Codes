#include <unistd.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
using namespace std;

int basic; // basic salary
int gender; //0 for male 1 for female
float perf; //performance percentage 
float bonus; //bonus percentage
float extra; //extra bonus for females with >90% performace
float total;
void input() {
    cout << "Enter basic salary : ";
    cin >> basic;
    cout << "Enter 0 if male 1 for female : ";
    cin >> gender;
    cout << "Enter performance percentege : ";
    cin >> perf;
    cout << "Enter bonus percentage : ";
    cin >> bonus;
    cout << "Enter extra bonus for female employees with >90\% performance : ";
    cin >> extra;
}
int main() {
    cout << "This is child process\n";
    input();
    pid_t pid = fork();
    
    if (pid!=0) {
        waitpid(pid, NULL, 0);
        cout << "This is parent process\n";
        total = basic * (1 + bonus / 100);
        if (gender & perf > 90) {
            total += basic * (extra / 100);
        }
        cout << "Total amount = " << total<< endl;
    }
    return 0;
}