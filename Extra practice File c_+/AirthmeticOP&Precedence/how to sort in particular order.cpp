#include<bits/stdc++.h>
using namespace std;
struct Interval {
    int start, end;
};
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
int main()
{
    Interval arr[] = { {1, 7}, {8, 6}, {3, 4}, {0, 9} };
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, compareInterval);
    cout << "Interval sorted by start time : \n";
    for (int i = 0; i < n; i++)
        cout << " [ " << arr[i].start << " , " << arr[i].end << " ] ";
    return 0;
}