// using pointer with Base class and Derived class 
#include<iostream>
using namespace std;
class Base {
    public:
    int a, b;
    Base(){
        a=0; b= 0;
    }
    void setvalue(int x, int y){
        a = x; 
        b=y;
        cout << "Base class fn" << "\n";
    }
    void printval(void){
        cout << "a is " << a << " b is " << b << "\n";
    }
};
class Derived: public Base{
    public:
    int c,d;
    Derived(){
        c=6;d=9;
    }
    void setvalue(int x, int y){
        a =x;
        b=y;
        cout << "Derived class fn" << "\n";
    }
    void printval(void){
        cout << "a is " << a << " b is " << b << " c is " << c << " d is " << d << "\n";
    }
};
int main()
{
    Base *d;
    Base e;
    d = &e;
    d->setvalue(1,2);
    d->printval();
    Derived *a;
    Derived b;
    a = &b;
    a->setvalue(2,4);
    a->printval();
    return 0;
}