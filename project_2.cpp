#include<iostream>
using namespace std;
class Sum {
    public: 
    double s,su;
    explicit Sum(double a_ = 0.0, double b_ = 0.0) : s(a_), su(b_) { } // NO implicit conversion is allowed 
    void disp() {cout << s <<  "\t" << su << "\n"; }
};
Sum operator+(const Sum &a, const Sum &b) { // Overload 1 
    return Sum(a.s + b.s, a.su + b.su);
} 
Sum operator+(const Sum &a, double d){
    Sum b(d); return a + b; // Create temprorary object and use Overload 1 
}
Sum operator+(double d, const Sum &b){
    Sum a(d); return a + b;        // Create temporary object and use Overload 1 
}
int main(){
    // double x1,x2,y1,y2;
    // cin>>x1>>x2>>y1>>y2;
    Sum a_(2.5, 3.2), b_(1.6, 3.3), c_; 
    // Sum a_(x1, y1), b_(x2, y2), c_;
    c_ = a_ + b_; c_.disp();        // c_ = 4.1 +j 6.5. Overload 1 
    c_ = a_ + 6.2; c_.disp();       // c_ = 8.7 +j 3.2 Overload 2
    c_ = 4.2 + b_; c_.disp();       // c_ = 5.8 +j 3.3 Overload 3  
}