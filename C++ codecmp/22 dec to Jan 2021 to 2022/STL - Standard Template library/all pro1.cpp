#include<iostream>
using namespace std;
template <class T>
class Matrix {
    public:
    T mtr[50][50];
};
int main()
{
    int a = 5, b = 6, c = 12;
    Matrix<int> x;
    Matrix<float> y;
    Matrix<double> z;
    return 0;
}
// Stacks ,Lists, Maps;//Standard Template Library
#include<iostream>
using namespace std;
int main()
{
    int a[50];
    // attendance - {"Ankit" : P,"Abhionav" : A,P A}
    //linked list 0(empty) .append(), +1, +1, +1, +1, .pop(), remove(), -1, -1
    //common data structures
    return 0;
}
//
#include<iostream>
using namespace std;
// STL - 
    // algorithms (functions)
        // merge sort, quick sort, tree sort, heap sort
    //containers (data structures)
        // vector, list(linked list-doubly), forward-list, tree, map
    // iterators
        //.begain(), .end();
int main()
{
    int a[50];
    // 0 - 49 cin >> a[i];
    // 0-49 cout << a[i];
    // quick- bubble sort, quick sort, merge sort......
    /*[ +1
    b[51]]
    copy a to b b(identical to a) +1 size*/
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
// STL - 
    // algorithms (functions)
        // merge sort, quick sort, tree sort, heap sort
    //containers (data structures)
        // vector, list(linked list-doubly), forward-list, tree, map
    // iterators
        //.begain(), .end();
int main()
{
    // vector
    int arr[50];
    vector<int> arr_vec;//(10, 0); size - 10 0, default all elements - 0;
    int temp;
    cin >> temp;
    arr_vec.push_back(temp); // size - 1 {temp}
    cin >> temp;
    arr_vec.push_back(1); // size - 2,{temp, 1}
    arr_vec.push_back(2); // size - 3, {temp, 1, 2}
    arr_vec.pop_back(); // size - 2,{56, 1}
    return 0;
}
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr_vec{9,2,3,8,5,7,6,4};
    for(int i = 0; i<arr_vec.size();i++){
        cout << arr_vec[i] << "\n";
    }
    cout << "Sorting ........" << "\n";
    sort(arr_vec.begin(),arr_vec.end()); //sort(&arr_vec[0],&arr_vec[6])
    for(int i = 0; i < arr_vec.size(); i++){
        cout << arr_vec[i] << "\n";
    }
    cout << "sorting in reverse ...." << "\n";
    reverse(arr_vec.end(), arr_vec.begin());
    for(int i = arr_vec.size();i>0; i--){
        cout << arr_vec[i] << "\n";
    }
    return 0;
}
//
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s = "testing";
    cout << s << "\n";
    cout << "------reverse the string ----" <<"\n";
    reverse(s.begin(), s.end());
    cout << s << "\n";
    
    return 0;
}
//
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
