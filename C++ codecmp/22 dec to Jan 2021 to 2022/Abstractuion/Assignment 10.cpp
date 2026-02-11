/*write a program to store the information of students in college.Then store all the objects data into an external file using file streams;*/
#include<iostream>
#include<fstream>
using namespace std;
class CollegeStudent {
    private:
    string name;
    int roll_no;
    int age;
    string department;
    static int total;
    public:
    CollegeStudent(){
        name = "";
        age = 0;
        department = "";
        total++;
        roll_no = total;
    }
    CollegeStudent(string n, int a, string d){
        name = n; age = a; department = d;
        total++;
        roll_no = total;
    }
    ~CollegeStudent(){
        total--;
    }
    void setData(string n, int a, string d){
        name = n; age = a; department = d;
    }
    void printData(){
        cout << "Student Record" << "\n";
        cout << "Name = " << name << "\n";
        cout << "Roll No = " << roll_no << "\n";
        cout << "Department = " << department << "\n";
        cout << "Age = " << age << "\n";   
    }
    friend ofstream & operator <<(ofstream&, CollegeStudent);
};
int CollegeStudent::total = 0;
int main() {
    CollegeStudent a, b, c, d, e, f;
    CollegeStudent g("Ankit", 18, "Computer Science");
    ofstream my_file;///output file stream

    my_file.open("my.txt", ios::app);
    my_file << a << b << c << d << e << f << g;
    my_file.close();
    return 0;
}
// output file operator overloading 
ofstream & operator <<(ofstream& out, CollegeStudent obj){
    out << "-----" << "\n";
    out << "Name = " << obj.name << "\n";
    out << "Roll.No = " << obj.roll_no << "\n";
    out << "Age = " << obj.age << "\n";
    out << "Department = " << obj.department << "\n";
    return out;

}
