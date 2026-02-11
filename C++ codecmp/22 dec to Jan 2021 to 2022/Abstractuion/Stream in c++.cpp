#include<iostream>
#include<fstream>
using namespace std;
class Student {
    public:
    string name;
    int rollno;
    float grade;
    static int totalstudents;
    Student(string n, float g){
        name = n; rollno = Student::totalstudents; grade=g;
        Student::totalstudents++;
    }
    friend ofstream & operator <<(ofstream&, Student&);
};
int Student::totalstudents = 1;
ofstream & operator <<(ofstream &file, Student& s){
    file << s.name << "\t";
    file << s.rollno << "\t";
    file << s.grade << "\n";
}
int main()
{
    Student a("Abhishek", 80.8);
    Student b("AnkitDimri", 56.78);
    Student c("Deepak", 78.89);
    ofstream my_file;
    my_file.open("no.txt", ios::app);
    my_file << a;
    my_file << b;
    my_file << c;
    //my_file << a.name << "\t" << a.rollno << "\t" << a.grade;
    // ifstream my_file;
    // my_file.open("my.txt");
    // int a;
    // while(!my_file.eof()){ // end of file - eof
    //     my_file >> a;
    //     cout << a << "\n";
    // }
    // my_file.close();
    return 0;
}