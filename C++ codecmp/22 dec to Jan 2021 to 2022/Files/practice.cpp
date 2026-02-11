#include<iostream>
using namespace std;
class Employee{
    private:
    string name;
    int age;
    string phone_no;
    string job_post;
    public:
    void setData(string n, int a, string p, string j){
        name = n;
        age = a;
        phone_no = p;
        job_post = j;
    }
    void putData(){
        cout << "-------Employee-------\n";
        cout << "\nName = " << name;
        cout << "\nAge = " << age;
        cout << "\nPhone No = " << phone_no;
        cout << "\nJob Post = " << job_post << "\n\n";     
    }
};
int main(){
    Employee a,b,c;
    a.setData("Ankit Dimri ", 29, "9870772993", "Tech Lead");
    b.setData("Sachin Dimri", 34, "9870772773", "Assistant Enginneer");
    c.setData("MahaDev Prasad Dimri", 56, "8979011618", "Civil Engineer");
    a.putData();
    b.putData();
    c.putData();
    return 0;
}