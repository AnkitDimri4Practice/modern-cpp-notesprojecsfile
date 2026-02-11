// #include<iostream>
// using namespace std;
// int linearSearch(int a[], int n) 
// {
//     int temp = -1;
//     for (int i = 0; i < 6; i++)
//     {
//         if (a[i] == n) 
//         {

//             cout << "Element found at position : " << i+1 << endl;
//             temp = 0;
//             break;
//         }
//     }
//     if (temp ==-1) 
//     {
//         cout << "No element found " << endl;
//     }
// }
// int main() 
// {
//     int arr[5];
//     cout << "Enter the 6 element of array " << endl;
//     for (int i = 0; i < 6; i++) 
//     {
//         cin >> arr[i];
//     }
//     cout << "Please enter an element to search " << endl;
//     int num;
//     cin >> num;
//     linearSearch(arr, num);
//     return 0;
// }
#include<iostream>
using namespace std;
int linearSearch(int a[], int n) {
    int temp = -1;
    for(int i = 1; i < 7; i++) {
        if(a[i] == n) {
            cout << "Element found at position : "  << i+1 << endl;
            temp = 0;
            break;
        } 
    } if (temp == -1) {
        cout << "NO element found! " << endl;
    } if (!n <= 0) {
        cout << " programe not accept -ve value : " << endl;
    }
}  
int main() {
    int arr[6];
    cout << "Enter the 7 element of the array: " << endl;
    for (int i = 1; i < 7; i++) {
        cin >> arr[i];
    }
    cout << "Please enteR an element to search: " << endl;
    int num;
    cin >> num;
    linearSearch(arr, num);
    return 0;
}