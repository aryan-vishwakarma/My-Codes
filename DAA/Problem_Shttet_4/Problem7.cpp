
#include <bits/stdc++.h>
using namespace std;

int st[40];
int n;
int candidate[40];
int target;
int no_in_candidate;

void inputSet() {
    cout << "Enter no. of elements in set : ";
    cin >> n;
    cout << "Enter the elements of the set\n";
    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }
}
void inputCandidate() {
    cout << "Enter no. of elements in candidate solution : ";
    cin >> no_in_candidate;
    cout << "Enter elements of candidate solution\n";
    for (int i = 0; i < no_in_candidate; i++) {
        cin >> candidate[i];
    }
}
bool inSet(int a) {
    for (int i = 0; i < n; i++) {
        if (a == st[i]) {
            return true;
        }
    }
    return false;
}
bool check() {
    int sum = 0;
    for (int i = 0; i < no_in_candidate; i++) {
        if (!inSet(candidate[i])) {
            return false;
        }
    }
    for (int i = 0; i < no_in_candidate; i++) {
        sum += candidate[i];
    }
    return (sum == target);
}
int main() {
    inputSet();
    cout << "Enter target : ";
    cin >> target;
    inputCandidate();
    if (check()) {
        cout << "Candidate solution is correct\n";
    }
    else {
        cout << "Candidate solution is NOT correct\n";
    }
    return 0;
}