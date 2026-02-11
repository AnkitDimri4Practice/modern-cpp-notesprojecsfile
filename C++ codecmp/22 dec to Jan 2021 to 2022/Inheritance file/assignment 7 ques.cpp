// Write two classes implementating, inheritance on the two. show use of 
//parameterized constructors of base class, while making Derived class object.
#include<iostream>
using namespace std;
class Student{ // Base class 
    protected:
    string name;
    int age;
    char grade;
    public: // public constructor
    Student(string n, int a, char g){
        name = n; age = a; grade = g;
    }
};
class HighSchoolStudent:public Student{ // Derived Class 
    private:
    string school_name;
    public:
    HighSchoolStudent(string n, int a, char g, string school):Student(n,a,g){
        school_name = school;
    }
    void printInfo(){
        cout << "Name of Student = " << name << "\n";
        cout << "Age of Student = " << age << "\n";
        cout << "Grade of Student = " << grade << "\n";
        cout << "name of the School = " << school_name << "\n";
    }
};
int main()
{
    HighSchoolStudent x("Ankit", 28, 'A'/*for char*/, "Greate Public School");
    x.printInfo();
    HighSchoolStudent y("Ankita", 26, 'B', "Himalayan Public School");
    y.printInfo();
    return 0;
}