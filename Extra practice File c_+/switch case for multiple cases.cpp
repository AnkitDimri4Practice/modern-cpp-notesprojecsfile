#include<iostream>
using namespace std;
int main()
{
    int gpa; // 0 to 4
    cout << "Please enter your score GPA!" << endl;
    cin >> gpa;
    // 0 -> terrible, 1 - > satisfactory, 2 -> average, 3 -> good, 4 -> brilliant
    switch (gpa)
    {
        case 0:
            cout << "Terriable" << endl;
            break;
        case 1:
            cout << "Satisfactory" << endl;
            break;
        case 2:
            cout << "Average" << endl;
            break;
        case 3:
            cout << "Good" << endl;
            break;
        case 4:
            cout << "Brilliant!" << endl;
            break;
        default:
            cout << "Invalid GPA enter" << endl;
     
    }
    return 0;

}