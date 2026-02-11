// write a program to check if an input matrix is symmetric or skewed symmetric or neither: 
#include<bits/stdc++.h>
using namespace std;
int main()
{    //program to check if a  matrix is a) symmetric, oor b) skewed symmetric or nither.
    int n; // order of my matrix..
    cout << "only a square matrix has the property to be symmetric or skewed - symmetric. " << "\n";
    cout << "please enter the squre matix order (n), such that the order would be n*n: " << "\n";
    cin >> n;
    int arr_a[n][n], arr_temp[n][n];
    cout << "please input all the elements of the array : " << "\n";
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            cin >> arr_a[i][j];
        }
    }
    cout << "calculating the transpose....." << "\n"; // finding transpose to array:: 
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            arr_temp[i][j] = arr_a[j][i];
        }
    }
    cout << "Checking if transpose is equal to input array (Checking for symmetry)" << "\n";
    bool is_symmetric = true;
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            if(arr_a[i][j] == arr_temp[i][j]) {
                continue;
            } else {
                is_symmetric = false;
                break;
            }
        }
        if(!is_symmetric){
            break;
        }
    }
    if(is_symmetric) {
        cout << "Input array is symmetric" << "\n";
    } else {
        cout << "input array is not symmetric" << "\n";
    }
    cout << "\n" << "now checking if it is skewed symmetric..." << "\n";
    bool is_skewed_symmetric = true;
    for(int i = 0; i<n; i++){
        for(int j=0;j<n;j++){
            if (arr_a[i][j] == -arr_temp[i][j]) {
                continue;
            } else {
                is_skewed_symmetric = false;
                break;
            }
        } 
        if(!is_skewed_symmetric){
            break;
        }
    }
    if (is_skewed_symmetric){
        cout << "Input matrix is skewed symmetric" << "\n";
    } else {
        cout << "input matrix is not skewed symmetric" << "\n";
    }
    return 0;
}