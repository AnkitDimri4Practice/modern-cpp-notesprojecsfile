#include<bits/stdc++.h>
using namespace std;
void PascalTringle(int n){
    for(int i = 1; i<=n; i++){
        int coef = 1;
        for(int k = n-i; k>0; k--){
            cout << " ";
        }
        for(int j = 1; j<=i; j++){
            cout << coef << " ";
            coef = (coef*(i-j)/j);        
        }
        cout << "\n";
    }
}
int main()
{
    int n;
    cout << "please enter the levels u want to print: ";
    cin >> n;
    PascalTringle(n);
    return 0;
}