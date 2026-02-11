#include<iostream>
using namespace std;
class base { // interface class
    public:
    int a, b;
    virtual void outpt() = 0; // pure virtual fn,
};
class Derived: public base {
    public:
    int c, d;
    Derived() {
        c =6; d=7;
    }
    void outpt(){
        cout << "Derived class fn " << "\n";
    }
};
int main() {
    Derived d;
    base *b = &d;
    b->outpt();
    return 0;
}
//
// Virtual Functions & Runtime polymorphism
#include<iostream>
using namespace std;
class base {
    public:
    int a,b;
    base(){
        a=1; b=9;
    }//wihout Virtual fn - Base class
    virtual void outpt() {//Derived Fn.
        cout << "Base class fn " << "\n";
    }
};
class Derived: public base {
    public:
    int c, d;
    Derived() {
        c =6; d=7;
    }
    void outpt(){
        cout << "derived class fn " << "\n";
    }
};
int main() {
    Derived d;
    base *b = &d;
    b->outpt();
    return 0;
}
//
#include<iostream>// new class fn…
using namespace std;
class base {
    public:
    int a,b;
    base(){
        a=1; b=9;
    } virtual void outpt() = 0;// purely virtual one
};
class Derived: public base {
    public:
    int c, d;
    Derived() {
        c =6; d=7;
    } void outpt(){
        cout << "Derived class fn " << "\n";
    }
}; class newclass: public base{
    public:
    void outpt(){
        cout << "new class fn" << "\n";
    }
}; int main() {
    Derived d;
    base *b = &d;
    b->outpt();
    newclass x;
    b=&x;
    b->outpt();
    return 0;
}
//
#include<iostream>
using namespace std;
class base {// abstract class
    public:
    virtual void outpt();// base class has all the entities purely virtual
};
class Derived: public base {
    public:
    int c, d;
    Derived() {
        c =6; d=7;
    }
    void outpt(){
        cout << "Derived class fn " << "\n";
    }
};
class newclass: public base{
    public:
    void outpt(){
        cout << "new class fn" << "\n";
    }
};
int main() {
    Derived d;
    base *b = &d;
    b->outpt();
    newclass x;
    b=&x;
    b->outpt();
    return 0;
}
//
class base {// abstract class- any class has
 a pure virtual fn become an abstract class.
 if all the entities of the abstract class 
only purly virtual
    public:
    int a, b;
    virtual void outpt() = 0;// pure virtual fn,
};
class Derived: public base {
    public:
    int c, d;
    Derived() {
        c =6; d=7;
    }
    void outpt(){
        cout << "Derived class fn " << "\n";
    }
};
int main() {
    Derived d;
    base *b = &d;
    b->outpt();
    return 0;
}
//
#include<iostream>
using namespace std;
class B;
class A{
    private:
    int gamma;
    public:
    int x, y;
    friend B;
};
class B { // has-a relationship
    public:
    A e;
    void checkingVal(){
        cout << "Derived class fn" << "\n";
        e.x=4;
        e.y=7;
        e.gamma = 6;
        cout << e.x << " " << e.y << " " << e.gamma << "\n";
    }
};
int main()
{
    B obj;
    obj.checkingVal();
    return 0;
}
//
// Static data member
// Static Members & Functions in c++ classes
#include<iostream>
using namespace std;
//int count = 0; // universal- Global variable 
class rectangle {
    private:
    int length;
    int breadth;
    int area;
    public:
    static int count;
    rectangle(){
        length = 0; breadth = 0; area = 0;
        count+= 12;
       // count++;
    }
    void putVal(int l, int b){
        length = l; breadth = b;
        area = l*b;
    }
    void displayVal(){
        cout << length << " " << breadth << "\n";
    }
};
int rectangle::count = 0;
int main()
{
    //rectangle a,b,c; // doesnt need an obj...
    cout << rectangle::count << "\n";
    /*cout << b.count << "\n";
    cout << c.count << "\n";*/
    /*a.putVal(1,4);
    b.putVal(3,7);
    c.putVal(4,9);*/
    // cout << count; Global variable
    return 0;
}
//
// Static data member
// Static Members & Functions in c++ classes
#include<iostream>
using namespace std;
class rectangle {
    private:
    int length;
    int breadth;
    int area;
    public:
    static int count;
    static int howmuchMemory(){
        return (count*12+4);
    }
    rectangle(){
        length = 0; breadth = 0; area = 0;
        count++;
    }
    void putVal(int l, int b){
        length = l; breadth = b;
        area = l*b;
    }
    void displayVal(){
        cout << length << " " << breadth << "\n";
    }
};
int rectangle::count = 0;
int main()
{
    rectangle a,b,c,d,e;
    cout << rectangle::count << "\n";
    cout << rectangle::howmuchMemory() << "\n";
    return 0;
}
//
#include<iostream>
using namespace std;
class A{ //outer class 
    public:
    class B { // has-a relationship // inner class
        public:
        int e, f;
        void testTwo(){
            cout << e << f << z;
        }
    };
    int a, b;
    static int z;
    B c;
};
// node, linkedlist
// outer class - linkedlist => inner class node
int main()
{
    return 0;
}
// Destructors in C++ classes
#include<iostream>
using namespace std;
class Base{
    public:
    Base(){
        cout << " 'Base' class constructors is called " << "\n";
    }//overlad to any function need 2 fn with same name but different parameters
    virtual~Base(){
        cout << " 'Base' class destructors is called..." << "\n";
    }//destructors cannot be overloaded
    // one confrigation of parameters.that will be blank and default//wen scope of a obj is fininshed / distroy the obj
};
class Derived: public Base{
    public:
    Derived(){
        cout << " 'Derived' class constructors is called " << "\n";
    }
    ~Derived(){
        cout << " 'Derived' class destructors is called " << "\n"; 
    }
};
// void fun(){
//     Base obj;
// }
int main(){
    //using pointer
    Base *a;
    Derived b;
    a = &b;
    // Base x;
    // cout << "done with base x declaration " << "\n";
    // Derived y;
    // cout << "done with derived object y declaration" << "\n";
    // fun();
    // cout << "back to int main()" << "\n";
    return 0;
}
//
/*write a class to store data of students in a college. imeplement multiple types of constructors,implement 
Destructors and use static data members or functions to issue a Rool no to every strudent class object.*/
#include<iostream>
using namespace std;
class collegeStudent{
    private:
    string name;
    int roll_no;
    int age;
    string department;
    static int total;
    public:
    collegeStudent(){
        name = "";
        age = 0;
        department = "";
        total++;
        roll_no = total;
    }
    collegeStudent(string n, int a, string d){
        name = n; age = a; department = d;
        total++;
        roll_no = total;
    }
    ~collegeStudent(){
        total--;
    } 
    void setData(string n, int a, string d){
        name = n; age = a; department = d;
    }
    void printdata(){
        cout << "Student Record" << "\n";
        cout << " Name = " << name << "\n";
        cout << " Age = " << age << "\n";
        cout << "Department = " << department << "\n" ;
        cout << "Roll No = " << roll_no << "\n";
    }
};
int collegeStudent::total = 0;
int main(){
    collegeStudent a,b,c,d,e,f;
    collegeStudent g("Ankit", 28,"Computer Science");
    g.printdata();
    return 0;
}
