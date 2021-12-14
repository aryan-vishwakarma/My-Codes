#include <bits/stdc++.h>
using namespace std;

int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

void getData() {
    cout << "\nEnter length of page reference sequence:";
    cin >> n;
    cout << "\nEnter the page reference sequence:";
    for (i = 0; i < n; i++)
        cin >> in[i];
    cout << "\nEnter no of frames:";
    cin >> nf;
}

void initialize() {
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data) {
    hit = 0;
    for (j = 0; j < nf; j++) {
        if (p[j] == data) {
            hit = 1;
            break;
        }

    }
    return hit;
}

int getHitIndex(int data) {
    int hitind;
    for (k = 0; k < nf; k++) {
        if (p[k] == data) {
            hitind = k;
            break;
        }
    }
    return hitind;
}

void dispPages() {
    for (k = 0; k < nf; k++) {
        if (p[k] != 9999)
            cout << p[k] << " ";
    }
}

void dispPgFaultCnt() {
    cout << "\nTotal no of page faults: " << pgfaultcnt << endl;
}

void fifo() {
    initialize();
    for (i = 0; i < n; i++) {
        cout << "\nFor " << in[i] << " : ";
        if (isHit(in[i]) == 0) {
            for (k = 0; k < nf - 1; k++)
                p[k] = p[k + 1];
            p[k] = in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            cout << "No page fault";
    }
    dispPgFaultCnt();
}

void optimal() {
    initialize();
    int near[50];
    for (i = 0; i < n; i++) {
        cout << "\nFor " << in[i] << " : ";
        if (isHit(in[i]) == 0) {
            for (j = 0; j < nf; j++) {
                int pg = p[j];
                int found = 0;
                for (k = i; k < n; k++) {
                    if (pg == in[k]) {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    near[j] = 9999;
            }
            int max = -9999;
            int repindex;
            for (j = 0; j < nf; j++) {
                if (near[j] > max) {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            cout << "No page fault";
    }
    dispPgFaultCnt();
}

void lru() {
    initialize();
    int least[50];
    for (i = 0; i < n; i++) {
        cout << "\nFor " << in[i] << " : ";
        if (isHit(in[i]) == 0) {
            for (j = 0; j < nf; j++) {
                int pg = p[j];
                int found = 0;
                for (k = i - 1; k >= 0; k--) {
                    if (pg == in[k]) {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    least[j] = -9999;
            }
            int min = 9999;
            int repindex;
            for (j = 0; j < nf; j++) {
                if (least[j] < min) {
                    min = least[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            cout << "No page fault!";
    }
    dispPgFaultCnt();
}

int main() {
    int choice;
    while (1)
    {
        cout << "\nPage Replacement Algorithms\n1. Enter data\n2. FIFO\n3. LRU\n4. Optimal\n5.Exit\nEnter your choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            getData();
            break;
        case 2:
            fifo();
            break;
        case 3:
            lru();
            break;
        case 4:
            optimal();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid Choice...";
            break;
        }
    }
}