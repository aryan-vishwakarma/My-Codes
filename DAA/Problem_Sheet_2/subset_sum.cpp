#include <bits/stdc++.h>
using namespace std;

static int nodes;

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << " " << A[i];
    cout << "\n";
}

int comparator(const void* pLhs, const void* pRhs) {
    int* lhs = (int*)pLhs;
    int* rhs = (int*)pRhs;
    return *lhs > *rhs;
}

void subset_sum(int s[], int t[],
    int s_size, int t_size,
    int sum, int ite,
    int const target_sum)
{
    nodes++;

    if (target_sum == sum) {
        printArray(t, t_size);
        if (ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum)
            subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    }
    else {
        if (ite < s_size && sum + s[ite] <= target_sum) {
            for (int i = ite; i < s_size; i++) {
                t[t_size] = s[i];
                if (sum + s[i] <= target_sum)
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
            }
        }
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int* tuplet = (int*)malloc(size * sizeof(int));
    int total = 0;

    qsort(s, size, sizeof(int), &comparator);
    for (int i = 0; i < size; i++)
        total += s[i];

    if (s[0] <= target_sum && total >= target_sum)
        subset_sum(s, tuplet, size, 0, 0, 0, target_sum);

    free(tuplet);
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int weights[n], target;
    cout << "Enter " << n << " values\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    cout << "Enter target value : ";
    cin >> target;
    generateSubsets(weights, n, target);
    cout << "Nodes generated " << nodes;
    return 0;
}