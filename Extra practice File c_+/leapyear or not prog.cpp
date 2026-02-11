#include <iostream>
using namespace std;
int main()
{
    int year;
    cout << " Please enter your year! " << endl;
    cin >> year;
    if (year % 4 == 0)
        {
            cout << " its a leap year! " << endl;
        }
        
    else
        {
            cout << "its not a leap year! " << endl;
        }
    return 0;
}