#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Employee {
    private:
    string name; string address; double sal_fixed; double sal_variable;
    public:
    Employee(){
        sal_fixed = 1200; 
        sal_variable = 12;
    }
    string get_name(){ return name; }
    void set_name(string name){ this->name = name; }
    void set_addr(string address){ this->address = address; }
    string get_addr(){ return address; }
    double get_sal_fixed() { return sal_fixed; }
    double salary(){ return sal_fixed + sal_variable; }
};
int main(){
    Employee e1;
    cout << "\nEmployee Name : " << e1.get_name() << "\nEmployee Address : " << e1.get_addr();
    cout<< "\nEmployee Salary : " << e1.salary();
    return 0;
}