#include<iostream>
using namespace std;
class Testing{
    private:
    int a,b;
    public:
    int c;
    float d,f;
    void se_default(void){
        a=1;
        b=4;
    }
    void print_values(void){
        cout << " A = " << a << " \n B = " << b;
        cout << " \n C = " << c << "\n D = " << d << "\n F = " << f;
    }
};
int main()
{
    Testing x,y;
    x.c = 23;
    x.d = 34.67;
    x.f = 32.56;
    x.se_default();
    y.se_default();
    x.print_values();
    y.print_values();
    return 0;
}