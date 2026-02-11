#include<iostream>
int main()
{
    auto result = (10 <=> 20) > 0;
    std::cout << result << std::endl;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    { 
        cout << word << " ";
    }
    cout << endl;
}

#include <iostream>
using namespace std;
constexpr int get_value(){
    return 4;
}
int main(){
    constexpr int value = get_value();
    cout << " value : " << value << "\n";
}
#include <iostream>
constexpr int get_value(){
	return 3;
}
int main(int argc, char **argv){
	std::cout << "Hello World in C++20!" << std::endl;
	return 0;
}
#include<iostream>
using namespace std;
int add_Numbers(float first_param, float second_param){
    int Result = first_param + second_param;
    return Result;
}
int main(int argc, char **argv){
    int first_number {23};
    int second_number = 34;
    int sum = first_number + second_number;
    cout << " Sum : " << sum << "\n";
    sum = add_Numbers(3,45);
    cout << " Sum " << sum << "\n";
    cout << " The sum of the two numbers: " << add_Numbers(199,455) << "\n";
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    std::cout << "Hello " << "\n";
    std::cout << "The no is 11 : " <<  12+1 << "\n"; 
    int age {21};
    std::cout << "The age is : " << age << "\n";
    std::cerr << "std::cerr output : something went wrong " << "\n"; // Error
    std::clog << "std::clog output : This is a log message" << "\n"; // log Message
    return 0; 
}
#include<iostream>
using namespace std;
int main()
{
    int age;
    std::string full_name;
    std::cout << "Please type in your last name and age, separated by spaces :  " << "\n";
    std::getline(std::cin,full_name);
    std::cin >> age;
    std::cout << "Hello " << full_name << "! You're " << age << "year old." << "\n"; 
    return 0; 
}
#include<iostream>
using namespace std;
int main()
{
    std::cout << "Hello C++20 " << "\n";
    int age{21};
    std::cout << "Age : " << age << "\n";
    std::cerr <<"Error message: something is wrong." << "\n";
    std::clog << "Log message : something happeend" << "\n";
    return 0; 
}
// Chapter 3: Variables and data types
// Variables and data types Introduction
//Number Systems
#include<iostream>
using namespace std;
int main() // int,float,double,char,bool,void,auto
{
    int n1=15;
    int n2 =017;
    int n3 = 0x0F;
    int n4 = 0b00001111;
    cout << "n1 - n4 : " << "\n" << n1 << "\n" << n2 << "\n" << n3 << "\n" << n4 << "\n" << "Thank Yoou";

return 0;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
constexpr int get_value(){
    return 8;
}
int main(int argc, char **argv)
{
    vector<string>msg{"The program is all about C++ coding soft skills"};
    for(const string& word: msg){
        cout << word << "\n";
    }
    constexpr int value = get_value();
    cout << "Value : " << value <<"\n";
    string full_name;
    int age;
    cout << "please enter the age and full name of the candidate : ";
    getline(cin,full_name);
    cin >> age;
    cout << " Hello, " << full_name << " You are " << age << " Year old. " << "\n";
    return 0;
}

// 3. Integer types : Decimals and Integers
#include<iostream>
using namespace std;
int main()
{
    // 1.  Braced initializer
    // variable may contain random garbage value. Warning 
    int elephant_count;
    int lion_count{};
    int dog_count{10};
    int cat_count{50};
    // can use expression as initializer
    int domesticated_animal {dog_count + cat_count};
    // int new_number{doesnt_exist};
    // int narrowing_conversion{2.9};
    cout << "Elephant count : " << elephant_count << "\n";
    cout << "Lion count : " << lion_count << "\n";
    cout << "Dog_Count : " << dog_count << "\n";
    cout << "Cat_count : " << cat_count << "\n";
    cout << " Domesticated animal : " << domesticated_animal << "\n";
    
    
    // 2. Functional initialization  
    int apple_count(5);
    int orange_count(10);
    int fruit_count(apple_count+orange_count);
    // int bad_initialization (doesnt_exist3+doesnt_exist4);
    // Information lost. less safe than braced initializers 
    int narrowing_conversion_functional(2.9);
    cout << "Apple count: " << apple_count <<"\n";
    cout << "Orange Count : " << orange_count << "\n";
    cout << "Fruit count : " << fruit_count << "\n";
    cout << "Narrowing conversion : " << narrowing_conversion_functional << "\n";
    
    // 3. Assignment notation 
    int bike_count{2};
    int truck_count{7};
    int vehicle_count = bike_count + truck_count;
    int narrowing_conversion_functional = 2.9;
    cout << " Bike count : " << bike_count << "\n";
    cout << " Truck count : " << truck_count << "\n";
    cout << "Vehicle count : " << vehicle_count << "\n";
    cout << "Narrowing conversion : " << narrowing_conversion_functional << "\n";
    
    // check the size with sizeof
    cout << " Sizeof int : " << sizeof(int) << "\n";
    cout << " Sizeof truck_count : " << sizeof(truck_count) << "\n";
    
    return 0;
}

// 4. Integer Modifiers
#include <iostream>
int main()
{
    std::cout << "-----------------------" << "\n";
    signed int value1{10};
    signed int value2{-300};
    std::cout << "Value1: " << value1 << "\n";
    std::cout << "Value2: " << value2 << "\n";
    std::cout << "sizeof(value1) : " << sizeof(value1) << "\n";
    std::cout << "Sizeof(value2) : " << sizeof(value2) << "\n";

    unsigned int value3{4};
    //unsigned int value4{-5}; Complier Error
    std::cout << "value 3 : " << value3 << "\n";
    std::cout << " A : " << sizeof(value3) << "\n";
    // std::cout << "value 4 : " << value4 << "\n";
    // std::cout << "Sizeof(value 4): " << sizeof(value4) << "\n";

    // short and long
    short short_var{-32768}; // 2 bytes
    short int short_int{455};
    signed short signed_short{122};
    signed short int signed_short_int{-456};
    unsigned short int unsigned_short_int{456};

    int int_var{55}; // 4 bytes
    signed signed_var{66};
    signed int signed_int{77};
    unsigned int unsigned_int{77};

    long long_var{88}; // 4 or 8bytes
    long int long_int{33};
    signed long signed_long{44};
    signed long int signed_long_int{44};
    unsigned long int unsigned_long_int{44};

    long long long_long{888}; // 8bytes
    long long int long_long_int{999};
    signed long long signed_long_long{444};
    signed long long int signed_long_long_int{1234};
    unsigned long long int unsigned_long_long_int{1234};
    std::cout << "----------------" << "\n";
    
    std::cout << "Short Variable : " << short_var << " , size : " << sizeof(short) << " Bytes " << "\n";
    std::cout << "Short int : " << short_int << " , size : " << sizeof(short_int) << "bytes" << "\n";
    std::cout << "signed Short : " << signed_short << " , size : " << sizeof(signed_short) << " Bytes " << "\n";
    std::cout << "signed Short int: " << signed_short_int << " , size : " << sizeof(signed_short_int) << " Bytes " << "\n";
    std::cout << "unsigned Short int: " << unsigned_short_int << " , size : " << sizeof(unsigned_short_int) << " Bytes " << "\n";
    std::cout << "--------------------------------" << "\n";

    std::cout << "int Variable : " << int_var << " , size : " << sizeof(int_var) << " Bytes " << "\n";
    std::cout << "signed var : " << signed_var << " , size : " << sizeof(signed_var) << " Bytes " << "\n";
    std::cout << "signed int: " << signed_int << " , size : " << sizeof(signed_int) << " Bytes " << "\n";
    std::cout << "unsigned int: " << unsigned_int << " , size : " << sizeof(unsigned_int) << " Bytes " << "\n";
    std::cout << "--------------------------------" << "\n";

    std::cout << "long Variable : " << long_var << " , size : " << sizeof(long_var) << " Bytes " << "\n";
    std::cout << "Long Int : " << long_int << " , size : " << sizeof(long_int) << "bytes" << "\n"; 
    std::cout << "signed long : " << signed_long << " , size : " << sizeof(signed_long) << " Bytes " << "\n";
    std::cout << "signed long int: " << signed_long_int << " , size : " << sizeof(signed_long_int) << " Bytes " << "\n";
    std::cout << "unsigned long int: " << unsigned_long_int << " , size : " << sizeof(unsigned_long_int) << " Bytes " << "\n";
    std::cout << "--------------------------------" << "\n";

    std::cout << "Long long  : " << long_long << " , size : " << sizeof(long_long) << " Bytes " << "\n";
    std::cout << "long Long Int : " << long_long_int << " , size : " << sizeof(long_long_int) << "bytes" << "\n"; 
    std::cout << "signed long long : " << signed_long_long << " , size : " << sizeof(signed_long_long) << " Bytes " << "\n";
    std::cout << "signed long long int: " << signed_long_long_int << " , size : " << sizeof(signed_long_long_int) << " Bytes " << "\n";
    std::cout << "unsigned long long int: " << unsigned_long_long_int << " , size : " << sizeof(unsigned_long_long_int) << " Bytes " << "\n";
    std::cout << "--------------------------------" << "\n";
    return 0;
}
Notes :: These modifiers only apply to integral types: those in which you can store decimal Numbers; 


// 5. Fractional Numbers
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    // Declare and initialize the variables
    float number1{1.12345678901234567890f};
    double number2{1.12345678901234567890};
    long double number3 {1.12345678901234567890L};
    // print out the sizes
    std::cout << "Sizeof float : " << sizeof(float) << "\n";
    std::cout << "Sizeof double : " << sizeof(double) << "\n";
    std::cout << "Sizeof long double : " << sizeof(long double) << "\n";
    cout << "----------------------------" << "\n";
    // Precision
    std::cout << setprecision(20); // control the precision from std::cout
    std::cout << "Number 1 = " << number1 << "\n"; // Precision : 7
    std::cout << "Number 2 : " << number2 << "\n"; // Precision : 15
    std::cout << "Number 3 = " << number3 << "\n"; // Precision : >double 15+ digits
    cout << "----------------------------" << "\n";

    // Float problem : The precision is usually too limited for a lot of applications 
    float number4 {192400023.0f}; // precision gone wrong suffix - 0f - same as double
    number4 = number4+1;
    std::cout << "Number 4 : " << number4 << "\n";
    cout << "----------------------------" << "\n";

    // scientific notation 1. What we have seen so far in terms of floating point types is fixed notaion.
    // There is another notation. scientific that is handy if you have really huge numbers or small numbers to represent.
    double number5 {192400023};
    cout << "Number 5: " << number5 << "\n";
    double number6{1.92400023e8};
    cout << "Number 6: " << number6 << "\n";
    double number7{1.924e8}; // Can ommit the lower 00023 for simplicty if our appplication allows
    cout << "NUmber 7 : " << number7 << "\n"; 
    double number8{0.00000000003498};
    cout << "Number 8 : " << number8 << "\n";
    double number9{3.498e-11}; // multiply with 10 exp(-11)
    cout << "Number 9 : " << number9 << "\n";
    double number10{5.6};
    double number11{};
    double number12{};
    cout << "----------------------------" << "\n" << "Infinity and NaN" << "\n";
    // Infinity
    double result {number10/number11}; 
    cout << number10 << "/" << number11 << " yields " << result << "\n";
    cout << result << " + " << number10 << " yields " << result + number10 << "\n";
    // NaN
    result = number11 / number12;
    std::cout << number11 << "/" << number12 << " = " << result << "\n";
    // Remember the suffixes when initializing floating point variables, otherwise the default will be double
    // Double works well in many situations, so you will see it used a lot
    return 0;
}
/* 6. Boolean
    A bytes can store 256 differnt values
    using it just to cover two states(true/false) is wasteful, especially for devices with hard memory constraints (think embedded devices)
    There are techniques to pack even more data into a byte. we'll learn more about these in a few upcoming chapters.
*/
#include <iostream>
using namespace std;
bool red_light{false};
bool green_light{true};
int main(){
    if (red_light == true){
        std::cout << "Stop!"
             << "\n";
    }else{
        std::cout << "Go through!"
             << "\n";
    }if (green_light){
        std::cout << " The light is green!"
             << "\n";
    }else{
        std::cout << "The light is not green!"
             << "\n";
    }
    // printing out a bool = 1-true, 0 - false
    std::cout << "\n";
    std::cout << "Red_Light : " << red_light << "\n";
    std::cout << "Green_light: " << green_light << "\n";
    // Sozeof()
    std::cout << "Sizeof(bool) : " << sizeof(bool) << "\n";
    // printing out a bool 1--> true, 0---> false
    std::cout << "\n";
    std::cout << "Red_light : " << red_light << "\n";
    std::cout << "Green_light : " << green_light << "\n";
       // print out true and false 
    std::cout << "\n";
    std::cout << std::boolalpha; // Forces the output format to true/false
    std::cout << "Red_light : " << red_light << "\n";
    std::cout << "Green_light: " << green_light << "\n";
}


/* 7. Character and Text   
    *It is possible to assign a valid ASCII code to a char variable, and the corresponding character will be stored in. 
     You can choose to imterpret that either as a character or a regular integral value
    * ASCII was a,ong the first encodings to represent text in a computer. 
    * It falls short whenit comes to representing languages other than English and a few western languages. Think East Asian laguages,,
    * There are better ways to represnt text that is meant to be seen in different languages, one of the most common being unicode
    * The details of unicode are out of scope for this course, just know that it's a robust way to represent text in different languages for computer 
*/
#include<iostream>
using namespace std;
int main()
{
    // one byte in memory : 2^8 = 256 different values (0~255)
    char value = 65; // ASCII character code for 'A'
    std::cout << " Value : " << value << std::endl;
    std::cout << "Value(int) : " << static_cast<int>(value) << "\n";
    int value_1 = 121; // ASCII character code for 'A'
    std::cout << " Value : " << value_1 << std::endl;
    std::cout << "Value(int) : " << static_cast<char>(value_1) << "\n";
    char character1{'a'};
    char character2{'r'};
    char character3{'r'};
    char character4{'o'};
    char character5{'w'};
    std::cout << character1 << "\n";
    std::cout << character2 << "\n";
    std::cout << character3 << "\n";
    std::cout << character4 << "\n";
    std::cout << character5 << "\n";
    return 0;
}
/* 8. Auto -->  Let the compiler deduce the type
*/
#include<iostream>
using namespace std;
int main()
{
    auto var1 {12}; // int
    auto var2 {13.0}; // float
    auto var3 {14.0f}; // double
    auto var4 {15.0l}; // long double 
    auto var5 {'e'}; // char 
    // int modifier suffixes
    auto var6 { 123u}; //unsigned 
    auto var7 { 123ul}; //unsigned long
    auto var8 { 123ll}; //long long 
    std::cout << "Var 1 occupies : " << sizeof(var1) << " bytes" << "\n";
    std::cout << "Var 2 occupies : " << sizeof(var2) << " bytes" << "\n";
    std::cout << "Var 3 occupies : " << sizeof(var3) << " bytes" << "\n";
    std::cout << "Var 4 occupies : " << sizeof(var4) << " bytes" << "\n";
    std::cout << "Var 5 occupies : " << sizeof(var5) << " bytes" << "\n";
    std::cout << "Var 6 occupies : " << sizeof(var6) << " bytes" << "\n";
    std::cout << "Var 7 occupies : " << sizeof(var7) << " bytes" << "\n";
    std::cout << "Var 8 occupies : " << sizeof(var8) << " bytes" << "\n";
    return 0;
}

/* 9. Assignments :
*/
#include<iostream>
using namespace std;
int main()
{
    int var1{123}; // Declare and initialize 
    std::cout << "Var1: " << var1 << "\n";
    var1=55; // Assign
    std::cout << "Var1: " << var1 << "\n";
    cout << "\n";
    double var2{44.55}; //Declare and initialize 
    std::cout << "var2 : " << var2 << "\n";
    var2 = 99.99; // Assign
    std::cout << "Var2 : " << var2 << "\n";
    cout << "\n";
    bool state{false}; // Declare and initialize 
    std::cout << std::boolalpha;
    std::cout << "State : " << state << "\n";
    state = true; // Assign
    std::cout << "state : " << state << "\n"; 
    cout << "\n";

    // Auto type deduction
    // Careful about auto assignment 
    auto var3{333u}; // Declare and initialize with type deduction
    var3 = -22; // Assign negative number. DANGAR!
    std::cout << "Var 3: " << var3 << "\n";
} 

 // This is a block comment that englobes multiple lines of text.