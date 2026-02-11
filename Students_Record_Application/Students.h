
#include<iostream>
#include<cstring>
using namespace std;
class Students{
    public: 
    typedef enum GENDER { male = 0, female };
    Students(char *n, GENDER g) : name(strcpy(new char[strlen(n) + 1], n)), gender(g){ }
    void setRoll(int r) { roll = r; }
    GENDER getGender() {return gender; }
    friend ostream& operator<< (ostream& os, const Students& s) {
        cout << ((s.gender == Students::male) ? "Male " : "Female ") << s.name <<  " " << s.roll << "\n";
        return os;
    }
    private: char *name; GENDER gender;
    int roll;
};
class Students_Regestered {
    Students **rec;
    int nStudents;
    public: Students_Regestered(int size) : rec(new Students*[size]), nStudents(0) { }
    void add(Students* s){ rec[nStudents] = s; s->setRoll(++nStudents); }
    Students *getStudent(int r){ return (r == nStudents + 1) ? 0 : rec[r-1]; }
};