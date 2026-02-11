#include<iostream>
#include<cmath>
using namespace std;
class Complex {
    private: double re_, im_; 
    public: Complex(): re_(0.0), im_(0.0){ /// Default constructor having no parameter 
        cout << "Ctor:: (" << re_ << ", " << im_ << ")" << "\n";
    }
    ~Complex(){  // Destructor 
        cout << "Dtor:: (" <<  re_ << ", " << im_ << ")" << "\n";
    }
    double norm() {
        return sqrt(re_*re_ + im_*im_);
    }
    void print(){
        cout << "|" << re_ << "+j" << im_ << "| = " << norm() << "\n"; 
    }
    void set(double re, double im) {
        re_ = re; im_ = im;
    }
};
int main(){
    Complex c; // Default constructor -- user provided
    c.print();  //print initial values 
    c.set(4.3,5.4); // set components
    c.print();      // print values set
} // Destructor 