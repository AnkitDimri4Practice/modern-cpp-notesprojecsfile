#include<iostream> // multiple Inheritance 
using namespace std;
class A{
    public:
    int a;
    A(){
        cout << "1.A class " << "\n";
    }
};
class B {
    public:
    B(){
        cout << "2.B class " << "\n";
    }
    int b;
};
class D: public A, public B{
    public:
    int d;
    D(){
        cout << "3.D class " << "\n";
    }
};
int main(){
    D x;
    return 0;
}
// Multi level Inheritance 
#include<iostream>
using namespace std;
class A{//Base Class 
    public:
    int a;
    A(){
        cout << "1.A class " << "\n";
    }
};
class B: public A { // Derived Class 1
    public:
    B(){
        cout << "2.B class " << "\n";
    }
    int b;
};
class C: public B{ // Derived Class 2
    public:
    int c;
    C(){
        cout << "3.C class " << "\n";
    }
};
int main(){
    C x;
    return 0;
}
// Function Overriding in C++
#include<iostream>
using namespace std;
class Base{
    public:
    int a, b;
    Base() {
        a = 0; b =0;
    }
    void setvalues(int x, int y){
        a = x; 
        b = y;
        cout << "Base class fn " << "\n";
    }
};
class Derived: public Base{
    public:
    int c, d;
    Derived() {
        c=0; d=0;
    }
    void setvalues(int x, int y){
        a=x;
        b=y;
        cout << "Derived class fn" << "\n";
    }
};
int main()
{
    Derived d;
    d.setvalues(1,2);
    return 0;
}
// using pointer with  fn Overriding & pointer 
#include<iostream>
using namespace std;
class Base{
    public:
    int a, b;
    Base() {
        a = 0; b =0;
    }
    void setvalues(int x, int y){
        a = x; 
        b = y;
        cout << "Base class fn " << "\n";
    }
};
class Derived: public Base{
    public:
    int c, d;
    Derived() {
        c=0; d=0;
    }
    void setvalues(int x, int y){
        a=x;
        b=y;
        cout << "Derived class fn" << "\n";
    }
    void printVal(void){
        cout << "a is : " << a << "b is : " << b << "c is = " << c << "d is " << d << "\n";
    }
};
int main()
{
    Base *d;
    Derived e;
    d = &e;
    cout << d->a << "\n";
    d->setvalues(2,5);
    return 0;
}