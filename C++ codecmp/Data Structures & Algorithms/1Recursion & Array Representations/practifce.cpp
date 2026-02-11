#include<iostream>
using namespace std;
int fun(int n){
    if(n>100){
        return n-10;
    } else {
        return fun(fun(n+11));
    }
}
int main()
{
    cout << "Nested recursive -> Value : " << fun(95) << "\n";
    return 0;

}