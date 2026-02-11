#include<bits/stdc++.h>
using namespace std;
void HDP(int n){
    for(int i = 1; i<n; i++){
        for(int j = i; j<n; j++){
            cout << " ";
        }
        for(int j=1;j<i;j++){
            if(j==1){
                cout << "* ";
            } else {
                cout << " ";
            }
        }
        for(int j =1;j<=i;j++)
        {
            if(j==i){
                cout << "* ";
            } else {
                cout << " ";
            }                
        }
        cout << "\n";
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<i;j++){
            cout << " ";
        }
        for(int j = i; j<n;j++){
            if(j==i){
                cout << "* ";
            } else {
                cout << " ";
            }
        }
        for(int j = i;j<=n;j++){
            if(j==n){
                cout << "* ";
            } else {
                cout << " ";
            }
        } 
        cout << "\n";           
    }
}
int main()
{
    int n;
    cout << "please enter the level of pattern: ";
    cin >> n;
    HDP(n);
    return 0;
}