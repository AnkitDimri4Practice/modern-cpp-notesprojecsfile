// The addition of compex nnumbers;

#include<iostream>
using namespace std;
struct Complex_No{
    int real;
    int imag;
};
Complex_No adding_complex (Complex_No, Complex_No);
int main() 
{
    Complex_No a,b,c;
    cout << "Enter the Real and imaginary part of the complex number respectively \n";
    cin >> a.real >> a.imag >> b.real >> b.imag;
    c = adding_complex(a,b);
    cout << "\n The complex number = " << a.real << " + i" << a.imag;
    cout << "\n The complex number = " << b.real << " + i" << b.imag;
    cout << "\n The Addition of complex number = " << c.real << " + i" << c.imag << "\n";
    return 0; 
}
Complex_No adding_complex(Complex_No a, Complex_No b){
    Complex_No output;
    output.real = a.real + b.real;
    output.imag = a.imag + b.imag;
    return (output);
}
// Employee Data in structure
#include<iostream>
#include<string>
using namespace std;
struct Employee{
    string name;
    int age;
    int salary;
    float performance;
};
int main()
{
    int n;
    cout << "Enter the total numbers of EMployee = " << "\n";
    cin >> n;
    Employee record[n];
    for(int i = 0; i<n; i++){
        cin >> record[i].name >> record[i].age >> record[i].salary >> record[i].performance;
        cout << "\n------ Employee--------";
        cout << "\n Name = " << record[i].name;
        cout << " \n Age = " << record[i].age;
        cout << "\n Salary = " << record[i].salary;
        cout << "\n performance = " << record[i].performance << "\n";
    } 
    return 0;
}
