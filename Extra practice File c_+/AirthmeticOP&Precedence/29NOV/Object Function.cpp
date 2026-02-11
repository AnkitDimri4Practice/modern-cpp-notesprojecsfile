#include<iostream>
using namespace std;
class Student {
public:
    string name;
    string major;
    double gpa;
    Student(string aName, string aMajor, double aGpa) {
        name = aName;
        major = aMajor;
        gpa = aGpa;
    }
    bool hasHonors() {
        if(gpa >= 2.0){
            return true;
        }
        return false;
    }
};
int main()
{
    Student Student1("jyoti", "Professor", 2.4);
    Student Student2("Ankita", "Juhari", 3.6);
    Student Student3("Deepak", "computer proggramer", 4.9);
    cout << Student1.hasHonors();
    return 0;
}