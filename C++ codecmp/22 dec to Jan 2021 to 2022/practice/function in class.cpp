// 1.Overload the operators “<<”, “>>”, “=”, for thr class defined in assignment last weels 
//assignment (to store Employee information) to I) take input, ii) print values, iii) copy object values,
#include<iostream>
using namespace std;
class Employee {
    private:
    string name;
    string phone_no;   
    string job_post;
    int age;
    public:
    friend ostream & operator << (ostream &out, Employee &c); // friend fns
    friend istream & operator >> (istream &in, Employee &c); // friend fns
    void operator = (Employee&); // member fns/methods
};
int main()
{
    Employee a,b;
    cin >> a;
    cout << a;
    b=a;
    cout << b;
    return 0;
}// for output
ostream & operator << (ostream &out, Employee &c){
    out << "----Employee Record---- " << endl;
    out << " Name = " << c.name << endl;
    out << " Phone_No = " << c.phone_no << endl;
    out << " Job_Post = " << c.job_post << endl;
    out << " Age = " << c.age << endl;
    return out;
}//for input
istream & operator >> (istream &in, Employee &c){
    cout << "Enter name of employee = ";
    in >> c.name;
    cout << "enter the phone no of the employee = ";
    in >> c.phone_no;
    cout << "enter the job post = ";
    in >> c.job_post;
    cout << "enter the age of the employee = ";
    in >> c.age;
    return in;
} 
// copying 
void Employee::operator = (Employee& b){
    // we get object b
    // let's say we want to do a = b(where a is the )
    // object that called the operator
    name = b.name;
    phone_no = b.phone_no;
    job_post = b.job_post;
    age = b.age;
    return;
} 