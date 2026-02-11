#include<iostream>
using namespace std;
class parent {
    private: // private elements cannt be inheritate
        int x;
    protected: // specifire 
        int wildcard; 
    public:
        int y,z;
};
class child: public parent { //public, private, protected
    private:
        int m;
    public:
        int n;
        void setvalue(int a, int b, int c, int d, int e){
           y = a;
           z = b;
           m = c;
           n = d; 
           wildcard = e;
        }
        void printval(void){
            cout << y << " " << z << " " << m << " " << n << " " << wildcard << "\n";
        }
};
int main()
{
    parent a;
    a.y = 10;
    cout << a.y << "\n";
    child b;
    b.setvalue(1,2,3,4,5);
    b.printval();
    return 0;
}