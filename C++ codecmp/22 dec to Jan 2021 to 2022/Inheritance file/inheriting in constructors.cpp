#include<iostream>
using namespace std;
class parent {
    protected:
        int x;
    public:
        parent(){
            x = 0;
            cout << "parent constructors called....." << "\n";
        }
        parent(int i) {
            x = i;
            cout << "parent parameters constructors called..." << "\n";

        }
};
class Child: private parent {
    private:
        int m;
    public:
        Child(){
            m = 0;
            cout << "Child default constructors called....." << "\n";
        } 
        Child(int a, int b): parent(b){
            m = a;
            cout << "Child parameterized constructors called......" << "\n";
        }
        void printval(void){
            cout << " m = " << m << " & n = " << parent::x << "\n";
        }
};
int main()
{
    Child b(2, 1);
    b.printval();
    return 0;
}
// #include<iostream>
// using namespace std;
// class A {
//     public:
//     int a;
// };
// class B: public A{ // has A relationship
//     public:
//     int b;
//     class A obj;
//     obj.a = 10;
//     obj.wd;   
// };
