#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>arr;
    int l, r;
    cout << "Enter value of bound L & R: " << endl;
    cin >> l >> r;

    int temp = 0;
    for (int i = l+1; i <= r-1; i++) {
        temp = i%10;
        if(temp == 2 || temp == 3 || temp == 9) {
            arr.push_back(i);
        } else {
            continue;
        }
    }
    cout << "Printing all the 'pretty value' between " << l << " and " << r << endl;
    for(int i = 0; i < arr.size(); i++) 
    {
        cout << arr[i] << endl;
    }
    return 0;
}