#include<iostream>
using namespace std;
/// try catch throw
int division(int, int);
int main()
{
    int a,b,c;
    cout << " Best divide program" << "\n";
    cin >> a >> b;
    try{
        c = division(a,b);
        cout << c << "\n";
    }
    catch(int e){
        cout << "trying to divide by zero : error Code  " << e << "\n";
    }
    catch(float e){
        cout << "trying to divide by zero. ERROR CODE" << e << "\n";
    }
    catch(...){
        cout << "handling all the rest error" << "\n";
    }
    return 0;
}
int division (int a, int b){
    if(b==0){
        throw (float)1.1;
    } else {
        return (a/b);
    }
}