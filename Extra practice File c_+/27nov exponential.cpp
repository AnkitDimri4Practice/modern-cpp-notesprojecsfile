#include<bits/stdc++.h>
using namespace std;
double application(double x){
    double result = exp(x);
    cout << "exp(x) = " << result << endl;
    return result;
}
int main(){
    double x;
    cout << "Enter the value of x: " << endl;
    cin >> x;
    cout << application(x);
    return 0;
}
