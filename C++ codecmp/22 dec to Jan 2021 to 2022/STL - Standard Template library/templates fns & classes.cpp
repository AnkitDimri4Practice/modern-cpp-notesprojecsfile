/* Given - A number is called pretty if it's last digit is 2,3,or 9, write a program that prints all the "Pretty Numbers" between two input numbers L(left) and R(right), such that any pretty number lies in the open range(L,R), [Implement STL Vector].*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr; // size - 0
    int l, r;
    cout << "Enter the values of bound L & R: " << "\n";
    cin >> l >> r;//
    int temp = 0;
    for(int i = l+1; i<r/*[i<=r-1]*/; i++){
        temp = i%10; // 5 => 5%10 -> 5, 
        if(temp==2 || temp==3 || temp==9){
            arr.push_back(i);
        } else {
            continue;
        }
    }
    cout << "Printing all the 'pretty values' between " << l << " and " << r << "\n";
    for(int i = 0; i<arr.size();i++){
        cout << arr[i] << "\n";
    }
    return 0;
}