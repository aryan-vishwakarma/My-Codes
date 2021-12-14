#include <bits/stdc++.h>
using namespace std;
int size;
int disk_size;
void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    cout << "Total number of seek operations = "
        << seek_count << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}
// int main()
// {
//     int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 };
//     int head = 50;
//     FCFS(arr, head);
//     return 0;
// }
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
}
// int main()
// {
//     int n = 8;
//     int proc[n] = { 176, 79, 34, 60, 92, 11, 41, 114 };
//     sstf(proc, 50, n);
//     return 0;
// }
void SCAN(int arr[], int head, int direction)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
    if (direction == 1)
        left.push_back(0);
    else if (direction == 2)
        right.push_back(disk_size - 1);
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
}
// int main()
// {
//     int arr[size] = { 176, 79, 34, 60,
//                     92, 11, 41, 114 };
//     int head = 50;
//     string direction = "left";
//     SCAN(arr, head, direction);
//     return 0;
// }
void CSCAN(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
    left.push_back(0);
    right.push_back(disk_size - 1);
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    head = 0;
    seek_count += (disk_size - 1);
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    cout << "Total number of seek operations = "
        << seek_count << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
}
// int main()
// {
//     int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 };
//     int head = 50;
//     cout << "Initial position of head: " << head << endl;
//     CSCAN(arr, head);
//     return 0;
// }
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
}
// int main()
// {
//     int arr[size] = { 176, 79, 34, 60,
//                     92, 11, 41, 114 };
//     int head = 50;
//     string direction = "right";
//     cout << "Initial position of head: "
//         << head << endl;
//     LOOK(arr, head, direction);
//     return 0;
// }
void CLOOK(int arr[], int head)
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
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    seek_count += abs(head - left[0]);
    head = left[0];
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
    cout << "Total number of seek operations = "
        << seek_count << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << endl;
    }
}
int main()
{
    cout << "Enter size of array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    // int arr[size] = { 176, 79, 34, 60,
    //                 92, 11, 41, 114 };

    int head;
    cout << "Enter Initial position of head : ";
    cin >> head;
    int choice;

    while (1) {
        cout << "\nEnter\n"
            << "1 for FCFS\n"
            << "2 for SSTF\n"
            << "3 for SCAN\n"
            << "4 for C-SCAN\n"
            << "5 for LOOK\n"
            << "6 for C-LOOK\n"
            << "7 to exit\n";
        cin >> choice;
        int direction;
        switch (choice) {
        case 1:
            FCFS(arr, head);
            break;

        case 2:
            sstf(arr, head);
            break;

        case 3:
            cout << "Enter direction\n1 for left and 2 for right : ";
            cin >> direction;
            cout << "Enter disk size : ";
            cin>>disk_size;
            SCAN(arr, head, direction);
            break;

        case 4:
            cout << "Enter disk size : ";
            cin >> disk_size;
            CSCAN(arr, head);
            break;

        case 5:
            cout << "Enter direction\n1 for left and 2 for right : ";
            cin >> direction;
            cout << "Enter disk size : ";
            cin >> disk_size;
            LOOK(arr, head, direction);
            break;

        case 6:
            cout << "Enter disk size : ";
            cin >> disk_size;
            CLOOK(arr, head);
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid Choice...\n";
        }
    }
    return 0;
}
