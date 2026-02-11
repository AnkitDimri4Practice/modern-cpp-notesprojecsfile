#include <iostream>
using namespace std;
int main ()
{
    int age;
    char initial;
    float height;

    cout << "please enter your age " << endl;
    cin >> age;
    cout << "please enter your initial";
    cin >> initial;
    cout <<" please enter your height" <<endl;
    cin >> height;

    cout << "Hi! " << initial << " of" << age << "age and" << height << " m height";

    return 0;
}