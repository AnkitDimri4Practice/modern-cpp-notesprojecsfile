#include<iostream>
#include<string>
using namespace std;
struct Employee{
    string Name;
    int age;
    int salary;
    float performance;
};
int main()
{
    int n,sum=0;
    cout << " please enter the No of employee in the company:  ";
    cin >> n;
    Employee record[n];
    for(int i = 0; i<n; i++){
        cin >> record[i].Name >> record[i].age >> record[i].salary >> record[i].performance;
        cout << "\nEmployee Name = " << record[i].Name;
        cout << "\nEmployee Age = " << record[i].age;
        cout << "\nEmployee Salary = " << record[i].salary;
        cout << "\nEmployee Performnce = " << record[i].performance << "\n";
        sum += record[i].salary;
    }
    cout << "\n Salary of the all employee in April month = " <<  sum << " ";

    return 0;
}