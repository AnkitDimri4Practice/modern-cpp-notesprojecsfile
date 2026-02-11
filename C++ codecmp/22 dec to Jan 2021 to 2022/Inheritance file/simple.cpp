#include<iostream> //Possible Functions in C++ classes
using namespace std;
class Complex_No{// constructors, destructors, mutators, accessors, enquiry, facilitators,
    private:
    int real;
    int imag;
    public:
    Complex_No(void){//default constructor
        real = 1;
        imag = 1;
    } 
    Complex_No(int x, int y){//parametrised cinst
        real = x;
        imag = y; 
    }// scope resolution operator :: define a function outside a class.
    Complex_No(const Complex_No& z){//copy constructors
        real=z.real;
        imag = z.imag;
    }
    void setvalues(int, int);
    bool isReal(void);
    Complex_No findProduct(Complex_No);
    inline void Display(void);
};
int main() {
    Complex_No a,b,c;
    a.setvalues(1,2);
    b.setvalues(3,4);
    a.Display();
    b.Display();
    c = a.findProduct(b);
    c.Display();
    cout << c.isReal() << "\n";
    return 0;
}// copy constructor
void Complex_No::Display(void){
    cout << real << "+ i" << imag << "\n";
} 
void Complex_No::setvalues(int x, int y){
    real = x;
    imag = y;
} 
bool Complex_No::isReal(void){
    if(imag==0){
        return true;
    } else {
        return false;
    }
}
Complex_No Complex_No::findProduct(Complex_No x){
    Complex_No z;
    z.real = real*x.real - imag*x.imag;
    z.imag = imag*x.real + real*x.imag;
    return z;
}
//Complex_No a;
    // a.setvalues(1,2);
    // Complex_No *b;
    // b = &a;
    // b->Display();
