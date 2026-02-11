#include<iostream>
using namespace std;
// try, catch, throw
int main()
{
    float a, b, c;
    cout << "Best divode programe..." << "\n";
    cout << "please enter the value of a and b = " << "\n";
    cin >> a >> b;
    try {
        if(b==0){
            throw 1;
        } else {
            throw 0;
        }
        c = a/b;
    cout << c << "\n"; // throw
    }
    catch (int e) {
        cout << "trying to divide by zero.. Error Code: " << e << "\n";
    }
    return 0;
}
