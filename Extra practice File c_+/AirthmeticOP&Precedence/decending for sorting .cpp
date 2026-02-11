#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 7, 8, 6, 3, 4, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, greater<int>());
    cout << "Array after sorting: \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}