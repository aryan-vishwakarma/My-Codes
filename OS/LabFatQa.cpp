#include <bits/stdc++.h>
using namespace std;
int size;
int disk_size;

void calculateDifference(int request[], int head, int diff[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}
int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void sstf(int request[], int head)
{
    if (size == 0)
    {
        return;
    }
    int diff[size][2] = { { 0, 0 } };
    int seekcount = 0;
    int seek_sequence[size + 1] = { 0 };
    for (int i = 0; i < size; i++)
    {
        seek_sequence[i] = head;
        calculateDifference(request, head, diff, size);
        int index = findMIN(diff, size);
        diff[index][1] = 1;
        seekcount += diff[index][0];
        head = request[index];
    }
    seek_sequence[size] = head;
    cout << "Total number of seek operations = "
        << seekcount << endl;
    cout << "Seek sequence is : " << "\n";
    for (int i = 0; i <= size; i++)
    {
        cout << seek_sequence[i] << "\n";
    }
    cout << "Average seek length is : " << ((float)seekcount / size) << endl;
}

void LOOK(int arr[], int head, int direction)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int run = 2;
    while (run--) {
        if (direction == 1) {
            for (int i = left.size() - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = 2;
        }
        else if (direction == 2) {
            for (int i = 0; i < right.size(); i++) {
                cur_track = right[i];
                seek_sequence.push_back(cur_track);
                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = 1;
        }
    }
    cout << "Total number of seek operations = "
        << seek_count << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
    cout << "Average seek length is : " << ((float)seek_count / size) << endl;
}
int main() {
    cout << "Enter no. of cylinders : ";
    cin >> disk_size;
    cout << "Enter current head position : ";
    int head;
    cin >> head;
    cout << "Enter no. of IO requests : ";
    cin >> size;
    int arr[size];
    cout << "Enter the IO requests\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Enter the direction for LOOK algoritms : 1 for left, 2 for right\n";
    int dir; cin >> dir;
    cout << "\nFOR SSTF\n";
    sstf(arr, head);
    cout << "\nFOR LOOK\n";
    LOOK(arr, head, dir);
}