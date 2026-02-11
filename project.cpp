#include<iostream>
using namespace std;
class Sum {
    double a_,b_;
    public:
    Sum(double a = 0.0, double b = 0.0): a_(a), b_(b){ }
    ~Sum(){ }
    void display();
    double s() { return s; }
    double su() { return su; }
    double set_s(double r) { s = r; }
    double set_su(double u) {su = u; }
};
void Sum::display(){
    cout << "Sum : " << s <<  ", Sum2 :  " << su << "\n";
}
Sum operator+(Sum &s1, Sum &s2){
    Sum s;
    s.set_s(s1.s() + s2.s());
    s.set_su(s1.su() + s2.su());
    return s;
}
int main(){
    Sum a_(34.3434,2323.2323), b_(344.343,24.4343),c_;
    cout << "1st Sum : "; a_.display();
    cout << "2nd Sum : "; b_.display();
    c_ = a_ + b_;
    cout << "Sum : "; c_.display();

}