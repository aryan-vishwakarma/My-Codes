#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};
struct Segment {
    Point left, right;
};

struct Event {
    int x, y;
    bool isLeft;
    int index;
    Event(int x, int y, bool l, int i) : x(x), y(y), isLeft(l), index(i) {}

    bool operator<(const Event& e) const {
        if (y == e.y)
            return x < e.x;
        return y < e.y;
    }
};
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}
bool doIntersect(Segment s1, Segment s2) {
    Point p1 = s1.left, q1 = s1.right, p2 = s2.left, q2 = s2.right;
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;
    return false;
}
set<Event>::iterator pred(set<Event>& s, set<Event>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}
set<Event>::iterator succ(set<Event>& s, set<Event>::iterator it) {
    return ++it;
}
int isIntersect(Segment arr[], int n) {
    unordered_map<string, int> mp;
    vector<Event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(Event(arr[i].left.x, arr[i].left.y, true, i));
        e.push_back(Event(arr[i].right.x, arr[i].right.y, false, i));
    }
    sort(e.begin(), e.end(), [](Event& e1, Event& e2) {return e1.x < e2.x;});
    set<Event> s;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        Event curr = e[i];
        int index = curr.index;
        if (curr.isLeft) {
            auto next = s.lower_bound(curr);
            auto prev = pred(s, next);
            bool flag = false;
            if (next != s.end() && doIntersect(arr[next->index], arr[index])) {
                string s = to_string(next->index + 1) + " " + to_string(index + 1);
                if (mp.count(s) == 0) {
                    mp[s]++;
                    ans++;
                }
            }
            if (prev != s.end() && doIntersect(arr[prev->index], arr[index])) {
                string s = to_string(prev->index + 1) + " " + to_string(index + 1);
                if (mp.count(s) == 0) {
                    mp[s]++;
                    ans++;
                }
            }
            if (prev != s.end() && next != s.end() && next->index == prev->index)ans--;
            s.insert(curr);
        }
        else {
            auto it = s.find(Event(arr[index].left.x, arr[index].left.y, true, index));
            auto next = succ(s, it);
            auto prev = pred(s, it);
            if (next != s.end() && prev != s.end()) {
                string s = to_string(next->index + 1) + " " + to_string(prev->index + 1);
                string s1 = to_string(prev->index + 1) + " " + to_string(next->index + 1);
                if (mp.count(s) == 0 && mp.count(s1) == 0 && doIntersect(arr[prev->index], arr[next->index]))
                    ans++;
                mp[s]++;
            }
            s.erase(it);

        }
    }
    for (auto& pr : mp) {
        cout << pr.first << "\n";
    }
    return ans;
}
void inputLine(Segment& a) {
    cout << "Enter coordinates of the left point\n";
    cin >> a.left.x >> a.left.y;
    cout << "Enter coordinates of the right point\n";
    cin >> a.right.x >> a.right.y;
}
int main() {
    int n;
    cout << "Enter number of line segments : ";
    cin >> n;
    Segment arr[n];
    for (int i = 0; i < n; i++) {
        cout << "For line no. " << (i + 1) << " :\n";
        inputLine(arr[i]);
    }
    cout << "Result...\n" << isIntersect(arr, n);
    return 0;
}