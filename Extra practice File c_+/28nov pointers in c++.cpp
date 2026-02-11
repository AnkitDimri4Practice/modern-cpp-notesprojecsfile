#include <iostream>
using namespace std;
int main()
{
    // pointer is just a memory address,type of a data
    int age = 19;
    int *pAge = &age;
    double gpa = 2.7;
    double *pGpa = &gpa;
    string name = "Ankit";
    string *pName = &name;
    cout << "Gpa: " << *&gpa << endl;
    cout << " Age:  "  << *&age << endl;
    return 0;
}