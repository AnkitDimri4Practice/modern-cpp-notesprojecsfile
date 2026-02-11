#include<iostream>
using namespace std;
int main()
{
    int year = 2020;
    cout << "Please enter the year! " << endl;
    cin >> year;
    if (year % 4 == 0) {
        cout << "Its a leap year! " << endl;
    } else {
        cout << "its not a leap year" << endl;
    }
    return 0;

}