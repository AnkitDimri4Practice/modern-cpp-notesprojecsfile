#include<iostream>
using namespace std;
class Base{
    private:
        int data1, data2;
    public:
        Base(int a = 0, int b = 0): data1(a), data2(b)
    {
        data1=a;
        cout<<"\n Enter data 1 = ";
        cin >> a;
        data2 = b;
        cout << "\n Enter data 2 = ";
        cin >> b;
    }
};
class Derived: public Base
{
public:
    void show(){
        cout << " data1 = " << data1 << "\n data2 = " << data2;
    }
};
int main()
{
    Derived d;
    d.show();
    return 0;
}