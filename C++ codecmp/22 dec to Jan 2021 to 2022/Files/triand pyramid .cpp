#include<bits/stdc++.h>
using namespace std;
void PyramidPattern1(int n){
    
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<(2*n);j++)
        {
            if(i+j<=n-1){
                cout << "*";
            } else { 
                cout << " ";
            }
            if((i+n)<=j){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    for(int i = 0; i<n; i++){
        for(int j=0; j<(2*n);j++){
            if(i>=j){
                cout << "*";
            } else {
                cout << " ";
            }
            if(i>=((2*n-1)-j)){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
void PyramidPattern2(int n){
    for(int i = 1; i<=n; i++){
        for(int k = n-i; k>0; k--){
            cout << " ";
        }
        for(int j = 1; j<=i; j++){
            cout << "* ";
        }
        cout << "\n";
    }
    for(int i = n-1; i>=1; i--){
        for(int k = n-i; k>0; k--){
            cout << " ";
        }
        for(int j = i; j>0; j--){
            cout << "* ";
        }
        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "please enter the levels of pattern : ";
    cin >> n;
    PyramidPattern1(n);
    PyramidPattern2(n);
    return 0;
}