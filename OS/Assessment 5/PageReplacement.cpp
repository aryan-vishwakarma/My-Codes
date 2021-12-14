#include<bits/stdc++.h>
using namespace std;

void FIFO(int pages[], int n, int capacity) {
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else {
            if (s.find(pages[i]) == s.end()) {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    cout << "Page Faults : "<< page_faults;
}

int LRU(int pages[], int n, int capacity) {
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        else {
            if (s.find(pages[i]) == s.end()) {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++) {
                    if (indexes[*it] < lru) {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }
    return page_faults;
}

bool search(int key, vector<int>& fr) {
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
int predict(int pg[], vector<int>& fr, int pn, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}
void optimalPage(int pg[], int pn, int fn) {
    vector<int> fr;
    int hit = 0;
    for (int i = 0; i < pn; i++) {
        if (search(pg[i], fr)) {
            hit++;
            continue;
        }
        if (fr.size() < fn)
            fr.push_back(pg[i]);
        else {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}
int main()
{
    // int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
    // int pn = sizeof(pg) / sizeof(pg[0]);
    // int fn = 4;
    // optimalPage(pg, pn, fn);
    // return 0;

    int n, fn, ch;
    cout << "Enter no. of pages : ";
    cin >> n;
    int pg[n];
    cout << "Enter the pages\n";
    for (int i = 0; i < n; i++) {
        cin >> pg[i];
    }
    cout << "Enter fn : ";
    cin >> fn;
    cout << "Enter\n1 for FIFO"
        << "\n2 for LRU"
        << "\n3 for Optimal\n";
    cin >> ch;
    switch (ch) {
    case 1:
        FIFO(pg, n, fn);
        break;
    case 2:
        LRU(pg, n, fn);
        break;
    case 3:
        optimalPage(pg, n, fn);
        break;
    default:
        cout << "Invalid Choice...\n";
    }
}
