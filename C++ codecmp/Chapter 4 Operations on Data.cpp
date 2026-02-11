// operation on datatypes
// 1-2. BAsic OPeration - add, subtract,divide, modules, multiply
#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin >> n1 >> n2;
    //Addition
    int sum {n1+n2};
    int other_sum = n1+n2+n1;
    std::cout << "The sum is: " <<sum << "\n";
    cout << "Other Sum : " << other_sum << "\n";
    cout << "\n";
    // Subtraction
    int Sub_1 {n1-n2};
    int other_sub1 = n1-n2-n1;
    std::cout << "The sub is: " <<Sub_1 << "\n";
    cout << "Other Sub : " << other_sub1 << "\n";
    cout << "\n";
    // Multiplication
    int pro {n1*n2};
    int other_pro= n1*n2*2;
    std::cout << "The pro is: " <<pro << "\n";
    cout << "Other pro : " << other_pro << "\n";
    cout << "\n";
    // Integer Division 
    int quotient {n1/n2}; 
    int other_quotient = n1/17;
    std::cout << "The Division is: " <<quotient << "\n";
    cout << "Other Division : " << other_quotient << "\n";
    cout << "\n";
    // MOdulus
    int modulus {n1%n2}; 
    std::cout << "The Modulus is: " <<modulus << "\n";   
}
// 3. Precedence [which operation to do first] and Associativity[which direction or which order]
#include<iostream>
using namespace std;
int main()
{
    int a{6},b{3},c{8},d{9},e{3},f{2},g{5};
    int result = a+b*c-d/e-f+g;
    cout << "Result : " << result << "\n";
     result = a/b*c+d-e+f;
     cout << " Result 2: " << result << "\n";
     result = (a+b)*c-d/(e-f)+g;
     cout << "Result 3 : " << result << "\n";
    return 0;
} 

// 4. prefix and postprefix + and -
#include<iostream>
using namespace std;
int main()
{
    cout << "\n" << "===regular increment and decrement ===" << "\n";
    int value{5}; 
    value = value + 1; // increment by one
    cout << "The value is : " << value << "\n";
    value = 5; // reset value to 5
    value = value -1; // Decrement by one
    cout << "The value is : " << value << "\n";
    
    cout << "\n" << "===Postfix increment / Decrement  with postfix===" << "\n";
    value = 6;
    cout <<"The value is (Incrementing) " << value++ << "\n" << " Value : " <<value << "\n";
    value = 6;
    cout <<"The value is (Decrementing) " << value-- << "\n" << " Value : " <<value << "\n";
    
    cout << "------------------------------------------------------------" << "\n";
    
    cout << "\n" << " === prefix Increment / decrement === " << "\n";
    value = 6,++value;
    cout <<"The value is (prefix++) " <<value << "\n";
    value = 6;
    cout <<"The value is (prefix++) " <<++value << "\n";
    value = 6,--value;
    cout <<"The value is (prefix--) " <<value << "\n";
    value = 6;
    cout <<"The value is (prefix--) " <<--value << "\n";
}
// 5. Compound Assignment 
#include<iostream>
using namespace std;
int main(){
    int value{45};
    value+=5;
    std::cout << "The value is : " << value << "\n";
    value/=3;
    std::cout << "the value is : " << value << "\n";
    value%=12;
    std::cout << "The value : " << value << "\n";   
}
// 6. Relational Operators : Comparing stuff
#include<iostream>
using namespace std;
int main(){
    int value{45};
    int value1{20};
    std::cout << "---------------------" << "\n";
    std::cout << "Value : " << value << "\n";
    std::cout << "Value1 : " << value1 << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << "Comparing variables : " << "\n";
    std::cout << boolalpha; // Make bool show up as true/false instead pf 1/0
    // Stress the need for parenthese here 
    std::cout << "value < value1:    " << (value < value1) << "\n";
    std::cout << "value <= value1:   " << (value <= value1) << "\n";
    std::cout << "value > value1:    " << (value > value1) << "\n";
    std::cout << "value >= value1:   " << (value >= value1) << "\n";
    std::cout << "value == value1:   " << (value == value1) << "\n";
    //cout << boolalpha;
    std::cout << "value != value1:   " << (value != value1) << "\n";
    std::cout << "---------------------" << "\n";
    std::cout <<"Store comparison result and use it later" << "\n";
    bool result = (value == value1);
    std::cout << value << " == " << value1 << " : " << result << "\n";
    std::cout << "---------------------" << "\n";
    return 0;
}
// 7. Logical Operators
#include<iostream>
using namespace std;
int main(){
    bool a{true};
    bool b{false};
    bool c{true};
    std::cout << "---------------------" << "\n";
    std::cout << boolalpha;
    std::cout << " a : " << a << "\n";
    std::cout << " b : " << b << "\n";
    std::cout << " c : " << c << "\n";
    // AND : Evaluates to true when all operands are true.
        // A single false operand will drag the entire expression to evaluating false.
    std::cout << "---------------------" << "\n";
    std::cout << " Basic AND operations " << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << " a && b   : " << (a && b) << "\n";
    std::cout << " a && c   : " << (a && c) << "\n";
    std::cout << " a && b && c : " << (a && b && c) << "\n";
    std::cout << "---------------------" << "\n";
    // OR : Evaluates to true when at least one operand true.
        // A single true operand will push the entire expression to evaluating true.
    std::cout << "---------------------" << "\n";
    std::cout << " Basic OR operations " << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << " a || b   : " << (a || b) << "\n";
    std::cout << " a || c   : " << (a || c) << "\n";
    std::cout << " a || b || c : " << (a || b || c) << "\n";
    // NOT : Negates whateve operand you put it with 
    std::cout << "---------------------" << "\n";
    std::cout << "Basic NOT operations " << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << " !a : " << !a << "\n";
    std::cout << " !b : " << !b << "\n";
    std::cout << " !c : " << !c << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << " Combine logical operators in expression " << "\n";
    std::cout << "---------------------" << "\n";
    int d{45};
    int e{20};
    int f{11};
    std::cout << "\n" << "-->Relational and logic operations on integers" << "\n";
    std::cout << " d: " << d << "\n";
    std::cout << " e: " << e << "\n";
    std::cout << " f: " << f << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << "(d > e) && (d > f)   : " << ((d > e) && (d >f)) << "\n";
    std::cout << "(d == e) || (d <= f) : " << ((d == e) || (d <= f)) << "\n";
    std::cout << "(d < e) || (d > f)   : " << ((d < e) || (d > f)) << "\n";
    std::cout << "(d > e) || (d < f)   : " << ((d > e) || (d < f)) << "\n";
    std::cout << "(d > f) && (f <= d)  : " << ((d > f) && (f <= d)) << "\n";
    std::cout << "(d > e) && (d <= f)  : " << ((d > e) && (d <= f)) << "\n";
    std::cout << "!(a &&b) || c        : " << (!(a &&b) || c) << "\n";
    std::cout << "(! a) && (d == e)    : " << ((! a) && (d == e)) << "\n";
    std::cout << "---------------------" << "\n";
    return 0;
} 
// 8.Output Formatting - I/O - manioulator 
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    std::cout << " ===== " << std::endl; // 1.st 
    std::cout << "This is a nice mmessage....." << std::endl << std::flush;
    // flushes the output buffer ti its final destination..
    // 2.dstd::flush --> causes immediate sending of data to the device connected to the stream

    std::cout << "----------------------------------" << endl;
    std::cout << "Unformatted table : " << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << endl;
    std::cout << "Stanley" << " " << "Woods" << " 33" << endl;
    std::cout << "Jorden" << " " << "Parker" << " 45" << endl;
    std::cout << "joe" << " " << "Ball" << " 21" << endl;
    std::cout << "josh" << " " << "Carr" << " 27" << endl;
    std::cout << "izaiah" << " " << "Robinson" << " 29" << endl;

    // https://en.cppreference.com/w/cpp/io/manip
    std::cout << "----------------------------------" << endl;
    std::cout << "Formatted table : " << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << std::setw(10) << "Lastname" << std::setw(10) << "Firstname" << std::setw(5) << "Age" << endl;
    std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" << endl;
    std::cout << std::setw(10) << "Stanley" << std::setw(10) << "Woods" << std::setw(5) << "33" << endl;
    std::cout << std::setw(10) << "Jorden" << std::setw(10) << "Parker" << std::setw(5) << "45" << endl;
    std::cout << std::setw(10) << "joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << endl;
    std::cout << std::setw(10) << "josh" << std::setw(10) << "Carr" << std::setw(5) << "27" << endl;
    std::cout << std::setw(10) << "izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << endl;
    
    int col_width{14};
    std::cout << "----------------------------------" << endl;
    std::cout << "Right Justified" << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << std::right; // left 
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << "Age" << endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "22" << endl;
    std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) << "Woods" << std::setw(col_width) << "33" << endl;
    std::cout << std::setw(col_width) << "Jorden" << std::setw(col_width) << "Parker" << std::setw(col_width) << "41" << endl;
    std::cout << std::setw(col_width) << "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width) << "21" << endl;
    std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width) << "27" << endl;
    std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width) << "29" << endl;
   
    std::cout << "----------------------------------" << endl;
    std::cout << "Internal Justified" << endl;
    // internal justified : sign is left justified , data is just jusstified.
    std::cout << "----------------------------------" << endl;
    std::cout << std::right;
    std::cout << std::setw(10) << -123.45 << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(10) << -123.45 << endl;

    std::cout << "----------------------------------" << endl;
    std::cout << "---std::setfill---" << endl;
    std::cout << "----------------------------------" << endl;
    col_width = 20;
    std::cout << std::left;
    std::cout << std::setfill('-'); // The fill character 
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << "Age" << endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Gray" << std::setw(col_width) << "22" << endl;
    std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width) << "Woods" << std::setw(col_width) << "33" << endl;
    std::cout << std::setw(col_width) << "Jorden" << std::setw(col_width) << "Parker" << std::setw(col_width) << "41" << endl;
    std::cout << std::setw(col_width) << "joe" << std::setw(col_width) << "Ball" << std::setw(col_width) << "21" << endl;
    std::cout << std::setw(col_width) << "josh" << std::setw(col_width) << "Carr" << std::setw(col_width) << "27" << endl;
    std::cout << std::setw(col_width) << "izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width) << "29" << endl;
    
    std::cout << "----------------------------------" << endl;
    std::cout << "---std::boolalpha---" << endl;
    std::cout << "----------------------------------" << endl;
    // boolalpha and noboolalpha : control bool output format : 1/0 or true/false
    bool condition {true};
    bool other_condition {false};
    std::cout << "Condition : " << condition << endl;
    std::cout << "other_condition : " << other_condition << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << std::boolalpha;
    std::cout << "Condition : " << condition << endl;
    std::cout << "Other_condition : " << other_condition << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << std::noboolalpha;
    std::cout << "Condition : " << condition << endl;
    std::cout << "Other_condition : " << other_condition << endl;

    std::cout << "----------------------------------" << endl;
    std::cout << "--- std::showpos ---" << endl;
    std::cout << "----------------------------------" << endl;
    // showpos and noshowpos : show or hide the + sign fro positive numbers
    int pos_num {34};
    int neg_num {-45};
    std::cout << "pos_num : " << pos_num << endl;
    std::cout << "neg_num : " << neg_num << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << std::showpos;
    std::cout << "pos_num : " << pos_num << endl;
    std::cout << "neg_num : " << neg_num << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << std::noshowpos;
    std::cout << "pos_num : " << pos_num << endl;
    std::cout << "neg_num : " << neg_num << endl;

    std::cout << "----------------------------------" << endl;
    std::cout << "---std::dec,hex,oct---" << endl;
    std::cout << "----------------------------------" << endl;
    // Different number systems: std::dec,hex,oct
    int pos_int {717171};
    int neg_int {-47347};
    double double_var{498.32};
    
    std::cout << "pos_int (dec) : " << pos_int << endl;
    std::cout << "neg_int (hex) : " << neg_int << endl;
    std::cout << "double_var (oct) : " << double_var << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << "pos_int in different bases : " << endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << "neg_int in different bases : " << endl;
    std::cout << "neg_int (dec) : " << std::dec << neg_int << endl;
    std::cout << "neg_int (hex) : " << std::hex << neg_int << endl;
    std::cout << "neg_int (oct) : " << std::oct << neg_int << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << "double_var in different bases : " << endl;
    std::cout << "double_var (dec) : " << std::dec << double_var << endl;
    std::cout << "double_var (hex) : " << std::hex << double_var << endl;
    std::cout << "double_var (oct) : " << std::oct << double_var << endl;
   
    std::cout << "----------------------------------" << endl;
    std::cout << "---std::showbase---" << endl;
    std::cout << "----------------------------------" << endl;
    // showbase and noshowbase : show the base for integral types
    std::cout << "pos_int (showbase : default) : " << endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << "neg_int (showbase : default) : " << endl;
    std::cout << std::showbase;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << endl;
    std::cout << "----------------------------------" << endl;

    std::cout << "----------------------------------" << endl;
    std::cout << "---std::uppercase---" << endl;
    std::cout << "----------------------------------" << endl;
    // uppercase and nouppercase 
    pos_int = 717171;
    std::cout << "pos_int (nouppercase : default) : " << endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << endl;
    std::cout << "----------------------------------" << endl;
    std::cout << "neg_int (uppercase : default) : " << endl;
    std::cout << std::uppercase;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << endl;
    std::cout << "pos_int (hex) : " << std::hex << pos_int << endl;
    std::cout << "pos_int (oct) : " << std::oct << pos_int << endl;
    std::cout << "----------------------------------" << endl;

    std::cout << "-------------------------------" << endl;
    std::cout << "---std::scientific, fixed ---" << endl;
    std::cout << "-------------------------------" << endl;
    double a{ 3.1415926535897932384626433832795 } ;
    double b{ 2006.0 };
    double c{ 1.34e-10 };
    std::cout << "double values (default : use scientific where necessary) : " << endl;
    std::cout << "a : " << a << endl;
    std::cout << "b : " << b << endl;
    std::cout << "c : " << c << endl;
    std::cout << "-------------------------------" << endl;
    std::cout << "double values (fixed ) : " << endl;
    std::cout << std::fixed;
    std::cout << "a : " << a << endl;
    std::cout << "b : " << b << endl;
    std::cout << "c : " << c << endl;

    std::cout << "------------------------------" << endl;
    std::cout << "---std::scientific, fixed(contd)---" << endl;
    std::cout << "-------------------------------" << endl;
    std::cout << "double values (scientific) : " << endl;
    std::cout << std::scientific;
    std::cout << "a : " << a << endl;
    std::cout << "b : " << b << endl;
    std::cout << "c : " << c << endl;
    std::cout << "-------------------------------" << endl;
    std::cout << "double values (back to defaults ) : " << endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::fixed;
    std::cout << "a : " << a << endl;
    std::cout << "b : " << b << endl;
    std::cout << "c : " << c << endl;
    std::cout << "------------------------------" << endl;

    std::cout << "------------------------------" << endl;
    std::cout << "---std::setprecision---" << endl;
    std::cout << "-------------------------------" << endl;
    // setprecision() : the number of digits printed out for a floating point default is 6
    a = 3.1415926535897932384626433832795;
    std::cout << "a (default precision(6)) : " << a << endl;
    std::cout << std::setprecision(10);
    std::cout << "a (precision(10)) : " << a << endl;
    std::cout << std::setprecision(20);
    std::cout << "a (precision(20)) : " << a << endl;
    std::cout << std::setprecision(50);
    std::cout << "a (precision(50)) : " << a << endl;
    std::cout << std::setprecision(6) << endl; // Reset precision to 6

    std::cout << "-------------------------------" << endl;
    std::cout << "---std::showpoint ---" << endl;
    std::cout << "-------------------------------" << endl;
    // showpoint and noshowpoint : show trailing zeros if necessary
    double d {34.1} ;
    double e {101.99};
    double f {12.0};
    int    g {45};
    std::cout << "noshowpoint (default): " << endl;
    std::cout << "d : " << d << endl;
    std::cout << "e : " << e << endl;
    std::cout << "f : " << f << endl;
    std::cout << "g : " << g << endl;
    std::cout << "-------------------------------" << endl;
    std::cout << "showpoint : " << endl;
    std::cout << std::showpoint;
    std::cout << "d : " << d << endl;
    std::cout << "e : " << e << endl;
    std::cout << "f : " << f << endl;
    std::cout << "g : " << g << endl;
    return 0;
}
// 9. Numeric Limits : 
#include<iostream>
#include<limits>
int main()
{
    std::cout << "The range for short is from                     : [" << std::numeric_limits<short>::min() << " -to -" << std::numeric_limits<short>::max() << "]\n";
    std::cout << "The range for unsigned short is from            : [" << std::numeric_limits<unsigned short>::min() << " -to -" << std::numeric_limits<unsigned short>::max() << "]\n";
    std::cout << "The range for int is from                       : [" << std::numeric_limits<int>::min() << " -to -" << std::numeric_limits<int>::max() << "]\n";
    std::cout << "The range for unsigned int is from              : [" << std::numeric_limits<unsigned int>::min() << " -to -" << std::numeric_limits<unsigned int>::max() << "]\n";
    std::cout << "The range for long is from                      : [" << std::numeric_limits<long>::min() << " -to -" << std::numeric_limits<long>::max() << "]\n";
    std::cout << "The range for float is from                     : [" << std::numeric_limits<float>::min() << " -to -" << std::numeric_limits<float>::max() << "]\n";
    std::cout << "The range(with lowest) for float is from        : [" << std::numeric_limits<float>::min() << " -to -" << std::numeric_limits<float>::max() << "]\n";
    std::cout << "The range(with lowest) for double is from       : [" << std::numeric_limits<double>::min() << " -to -" << std::numeric_limits<double>::max() << "]\n";
    std::cout << "The range(with lowest) for long double is from  : [" << std::numeric_limits<long double>::min() << " -to -" << std::numeric_limits<long double>::max() << "]\n";
    std::cout << "The range for long is from ------------------   : [" << std::numeric_limits<long>::min() << " -to -" << std::numeric_limits<long>::max() << "]\n";
    // other facilities 
    std::cout << "int is signed -   -   -   -   -   -   -   -   - : " << std::numeric_limits<int>::is_signed << "\n";
    std::cout << "int digits    -   -   -   -   -   -   -   -   - : " << std::numeric_limits<int>::digits << "\n";
    return 0;
}
// 10. Math Functions
#include <iostream>
#include <cmath>
int main()
{
    double weight{7.7};
    std::cout << "--------------------------------------" << "\n";
    // floor - 7
    std::cout << "weight rounded to floor : " << std::floor(weight) << "\n";
    
    // ceil - 8
    std::cout << "weight rounded to ceil is : " << std::ceil(weight) << "\n";
   std::cout << "--------------------------------------" << "\n";
    
    // abs Absolute
    double saving{-5000};
    weight = 7.7;
    std::cout << "Abs of weight is : " << std::abs(weight) << "\n";
    std::cout << "Abs of saving is : " << std::abs(saving) << "\n";
    std::cout << "--------------------------------------" << "\n";
    
    // exp(x) = e^x where e = 2.71828
    double exponential = std::exp(10);
    std::cout << "The exponential of 0 is : " << exponential << "\n";
    std::cout << "--------------------------------------" << "\n";
    
    // pow - power
    std::cout << "3 ^ 4 is : " << std::pow(3, 4) << "\n";
    std::cout << "9^3 is : " << std::pow(9, 3) << "\n";
    std::cout << "--------------------------------------" << "\n";
    
    /* Log" : reverse function of pow. if 2^3 = 8, log 8 in base 2 = 3. Log is like asking to which exponent should we elevate 2 to get eight ? Log,
    by defalut computes the log in base e. There also is another function which uses base 10 called log10
    Try to reverse operation of e^4 = 54.59, it will be log 54.59 in base e = ?
    */
    std::cout << "log ; to get 54.59, you would elevate e to the power of : " << std::log(54.59) << "\n";
    //    log 10 , 10^4 = 10000. to get 10k, you'd need to elevate 10 to the power of ? , this is log in base 10
    std::cout << "to get 10000, you'd need to elevate 10 to the power of : " << std::log10(10000) << "\n";
    std::cout << "--------------------------------------" << "\n";
    
    // sqrt - square root 
    std::cout << "the square root of 81 is : " << std::sqrt(81) << "\n";
    //  round . Halfway points are rounded away from 0.2,5 is rounded to 5 for example
    std::cout << "3.654 rounded to : " << std::round(3.654) << "\n";
    std::cout << "2.5 is rounded to : " << std::round(2.5) <<"\n";
    std::cout << "2.4 rounded to : " << std::round(2.4) << "\n";
    std::cout << "--------------------------------------" << "\n";

}
/*
11. Weried integral types --->

  Integral Types - less than 4 bytes in size don't support arithmetic operations
    char ------- short int
    * The same behavior is present on other operators like bitwise shift operators (>> and <<).
*/
#include<iostream>
int main()
{
    short int var1 {10}; // 2bytes
    short int var2 {20};
    char var3 {40}; // 1bytes 
    char var4 {50};
    std::cout << "Size of var1 : " << sizeof(var1) << "\n";
    std::cout << "Size of var2 : " << sizeof(var2) << "\n";
    std::cout << "Size of var3 : " << sizeof(var3) << "\n";

    auto result1 = var1 +var2;  // Conversion to int
    auto result2 = var3 + var4; // beacuse the int is the smallest type 

    std::cout << "Size of result1 : " << sizeof(result1) << "\n"; // 4
    std::cout << "Size of result2 : " << sizeof(result2) << "\n"; // 4
}
