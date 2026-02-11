//  Pointers  ---> Declaring pointers
#include<iostream>
int main()
{
    int * p_number{}; // can only store an address of a variable of type int
    double * p_fractional_number{}; // can only store an address of a variable of type double
    //  Explicitely initialize to nullptr
    int * p_number1{nullptr}; // will initialize with nullptr
    int * p_fractional_number1{nullptr};
    std::cout << "------------------" << "\n";
    std::cout << "Assigning data to pointer variables...." << "\n";
    std::cout << "Pointers to different variables are the same size " << "\n";
    std::cout << "Sizeof(int) : " << sizeof(int) << "\n";// 4
    std::cout << "sizeof(double) : " << sizeof(double) << "\n";
    std::cout << "Sizeof(double*) : " << sizeof(double*) << "\n";
    std::cout << "sizeof(int*) : " << sizeof(int*) << "\n";
    std::cout << "sizeof(p_number1) : " << sizeof(p_number1) << "\n";
    std::cout << "sizeof(p_fractional_number1) : " << sizeof(p_fractional_number1) << "\n";
    std::cout << "------------------" << "\n";
    std::cout << "All pointer variables have the same size...." << "\n";
    std::cout << " Size of number pointer : " << sizeof(p_number) << ", size of int : " << sizeof(int) << "\n";
    std::cout << " Size of fractional_number pointer : " << sizeof(p_fractional_number) << ", size of int : " << sizeof(int) << "\n";
    std::cout << " Size of number1 pointer : " << sizeof(p_number1) << ", size of int : " << sizeof(int) << "\n";
    std::cout << " Size of p_fractional_number1 pointer : " << sizeof(p_fractional_number1) << ", size of double : " << sizeof(double) << "\n";
    std::cout << "------------------" << "\n";
    std::cout << "Position of the * doesn't matter...." << "\n";
    int* p_number2{nullptr};
    int * p_number3{nullptr};
    int *p_number4{nullptr};// All work the same ..int *p_number4 fromat is easier to understand when you have multiple variables declared on the same line...
    int *p_number5, other_int_var{};
    int* p_number6, other_int_var6{}; // confusing as you wonder if other_int_var6 is also a pointer to int. It is not The structure is exactly the same for the previous statement 
    //  It is better to seperate these declarations on different lines though
    int *p_number7{};
    int other_int_var7{}; /// No room for confusion this time..
    std::cout << "------------------" << "\n";
    std::cout << "Assigning data to pointer variables...." << "\n";
    //  initializing pointers and assigning them data
    //  We know that pointers store addresses of variables 
    int int_var{43};
    int *p_int{&int_var};// The address of operator (&);
    std::cout << "int_Var : " << int_var << "\n";
    std::cout << "p_int (Address in memory) : " << p_int << "\n";
    //   you can also change the address stored in a pointer any time
    int int_var1{65};
    int_var1=125;
    p_int = &int_var1; // aSSIGN A different address to the pointer 
    std::cout << "p_int(with different address) : " << p_int << "\n";
    //  can't cross assign between pointers of different types 
    int *p_int1{nullptr};
    double double_var{33};
    // p_int = & double_var; // Compiler error
    // Dereferencing a pointer : 
    int* p_int2{nullptr};
    int int_data{56};
    p_int2=&int_data;
    std::cout << "Value : " << *p_int2 << "\n";
}
/*  Pointer to char--> declaring  pointers to char [17-05-2022]
can use normal pointer to char like we've been doing for double, int and anything else really */ 
#include<iostream>
int main()
{
    char *p_char_var{nullptr};
    char char_var{'A'};
    p_char_var = &char_var;
    std::cout << "The value stored in p_char_var is : " << * p_char_var << "\n";
    char char_var1{'C'};
    p_char_var = &char_var1;
    std::cout << "the value stored in p_char_var is : " << * p_char_var << "\n";
    std::cout << "-------------" << "\n";
    std::cout << " initialize with string literal" << "\n";
    //  Pointer to char can alse do something sppecial. You can initialize with a string literal : C-string 
    char * p_message{"Hello Peg!"};
    //  Printing out 
    //  what do we get when we print this out with std::Cout 
    std::cout << "The message is : " << p_message << "\n";
    //  What do we get when we dereference the pointer
    std::cout << "The value stored at p_message is : " << * p_message << "\n";
    std::cout << "---------------------------" << "\n";
    std::cout << "The string literal is made up of const char. trying to modify any of them will result in a disaster...!" << "\n";
    // *p_message ='B'; // wee want the message to say Bello Wolrd!
    std::cout << "The message is(after modification of first char to B) : " << p_message << "\n";
    std::cout << "---------------------------" << "\n";
    std::cout << "Can modify the pure array initialized with string literal"<<"\n";
    char message2[]{"Hello APOOJ!"};
    message2[0]='T';
    std::cout << "Message2 : " << message2 << "\n";
}
// Program Memory Map
#include<iostream>
int add_number(int a,int b){
    return a+b;
}
int main()
{
    /* Virtual Memory ---> A trick that fools your program into thinking it is the only program running on your OS, and all memory resources belonng to it..---> Memory Map 
    Each program is abstracted  into a process,a and each process has access to the memory range 0~2^(N)-1 where N is 32 on 32 bit systems and 64 on 64 bit systems.
    -->
        The entire program is not loadedd in real memory by the CPU and MMU.. only parts that are about to be executed are loaded. Making effective use of real memory, a valuable and lacking resoource.
 
    --> 
        tHE MEMORY  map is a statndard format defined by the OS.. All rpograms written for that OS must conform to it. It is usually divided into some sections.
    [[-->   System  -->     stack -->      Heap -->     Data -->    Text    <--]
    */ 
    int a{10}, b{5}, c; 
    std::cout << "Statement1 : " << a << "\n";
    std::cout << "Statement2 : " << b << "\n";
    c= add_number(a,b);
    std::cout << "Statement3 : " << c << "\n";
    std::cout << "Statement4 : " << add_number(12,45)<< "\n";
    /*
     Dynamic Memory alocation
    - Local variables , function calls.....
    - Additional memory that can be queried for at run time...
    */
    //     How we've used pointers so far
    std::cout << "0------------------------------------0" << "\n";
    int number {55};
    int * p_number = &number;
    std::cout << "\nDeclearing pointer and assigning address : " << "\n";
    std::cout << "Number : " << number << "\n";
    std::cout << "p_number : " << p_number << "\n";
    std::cout << "&number : " << &number << "\n";
    std::cout << "*p_number : " <<*p_number << "\n"; 
    
    int * p_number1; // Uninitialization pointer, contains junk address
    int number1{12};
    p_number1 = &number1; // Make it point to a valid address
    std::cout << "\nUninitialize pointer : " << "\n";
    std::cout << "*p_number1 : " << *p_number1 << "\n";
    std::cout << "0---------------------------0" << "\n";
    std::cout << "Bad Things ------" << "\n";
    //  Writting into uninitilazed pointer through derefrence 
    int *p_number2; // Contains junk address: could be anything
    *p_number2 =33; // Writting into ju nk address : BAD!
    std::cout << "\nWritting into uninitialized pointer through derefrence " << "\n";
    std::cout << "p_number2 : " << p_number2 << "\n"; // Reading from the junk address.
    std::cout << "*p_number2 : " << *p_number2 << "\n";
    //  Initializing pointer to null
    //  int *p_number3{nullptr}; // also works 
    int * p_number3{}; // initialized with pointer equivalent of zero : nullptr 
                                    //  A pointer pointing nowhere
    // *p_number3 {55}; // Writting into a pointer pointing nowhere : BAD , CRASH
    std::cout << "\nREading and witting through nullptr : " << "\n";
    // std::cout << "p_number3 : " << p_number3 << "\n";
    // std::cout << "*p_number3 : " << *p_number3 << "\n"; // Reading from nullptr BAD,CRASH
    
    /* So far we've only been using memory allocated on the stack. We are going to see how one can allocate memory from the heap,  and some of the differences between these mechanisms.
    */ 
    return 0; 
}
#include<iostream> // 01-06-2022
int main(int argc, char **argv){
    std::cout << "------Lifetime through scope mechanism--------" << "\n"; 
    {
        int local_scope_var{33};
    }
    std::cout << " ------------- " << "\n";
    std::cout << " Stack lifetime vs heap lifetime"<< "\n";
    {
        int local_var{33};
        int *local_ptr_var = new int;
    }
    
    //  Allocate dynamic memory through 'new'
    //  Initialize the pointer with dynamic memory. Dynamically allocate memory at run time and make a pointer point to it..
    int *p_number4{nullptr}; // Releasing and resetting 
    p_number4 = new int; 
    delete p_number4;
    p_number4=nullptr;
    /* Dynamically allocate space for a single int on the heap This memory belongs to our program from now on. The system can't use it for anything else. untill we return it. After this line executes, we will have a valid memory location allocated. the size of the allocated memory will be such that it can store the type pointed to by the pointer
    */
   *p_number4 = 77; // Writting into dynamicalyy allocated memory 
   std::cout << "\nDynamically allocating memory : " << "\n";
   std::cout << "*p_number4 : " << *p_number4 << "\n";

   std::cout << "Initialize with 'new' upon pointer declaration " << "\n";
    //  It's also possible to initialize the pointer with a valid address upon decleration. Not with a nullptr
    int *p_number5{ new int}; // Memory location contains junk value
    int *p_number6{ new int (22)}; // use direct initialization
    int *p_number7{ new int {23}}; // use unform initialization 
    std::cout << "\nInitialize with valid memory address at declaration : " << "\n";
    std::cout << "p_number5 : " << p_number5 << "\n";
    std::cout << "*p_numbe5 : " << *p_number5 << "\n";
    std::cout << "p_number6 : " << p_number6 << "\n";
    std::cout << "*p_number6 : " << *p_number6 << "\n";
    std::cout << "p_number7 : " << p_number7 << "\n";
    std::cout << "*p_number7 : " << *p_number7 << "\n";
    //  remember to release the memory 
    delete p_number5;
    p_number5=nullptr;
    delete p_number6;
    p_number6=nullptr;
    delete p_number7;
    p_number7=nullptr;
    std::cout << "Calling delete twice on a pointer : BAD!" << "\n";
    // Calling delete on a pointer twice will lead to undefined behaviour. Your program may even crash! Avoid this like a plague!
    p_number6 = new int{77};
    //  use the pointer
    std::cout << "\nDeleting twice : BAD!" << "\n";
    std::cout << "p_number6: " << p_number6 << "\n";
    std::cout << "*p_number6 : " << *p_number6 << "\n";
    // remember to release any dynamically allllocated piece of memory 
    delete p_number6;
    delete p_number6; // Anything can happen.
    p_number6 = nullptr; 

    int* p_number8 = new int;
    delete p_number8;
    delete p_number8;
    std::cout << "After deleting twice " << "\n";
    return 0;
} 
// 11-06-22
/* Dangling Pointers -->
        A Pointer that doesn't point to valid memoru address. Trying to dereference and use a dangling pointer will result in undefined behavior.
        - uninitialized pointer 
        - Deleted pointer
        - Multiple pointers pointing to same memory.

    2.  -  Initialize your pointers
        - Reset pointers after delete 
        - For multiple pointers to same address,make sure the owener pointer is very clear 



*/
#include<iostream>
using namespace std;
int main()
{
    int * p_number; // Dangling uninitialized pointer
    cout << "\n Case 1: uninitialized pointer : "  << "\n";
    cout << "p_number : " << p_number << "\n";
    // cout << "*p_number : " << *p_number << "\n";

    cout << "--------------------------" << "\n";
    cout << "Deleted Pointer" << "\n";
    cout << "--------------------------";
    cout << "\n Case 2 : Deleted pointer " << "\n";
    int * p_number1{new int{67}};
    cout << "*p_number1(before delete) : " << *p_number1 << "\n";
    delete p_number1;
    cout << "*p_number1(after delete) : " << *p_number1 << "\n";
    cout << "--------------------------" << "\n";
    cout << "Multiple pointers pointing to same address" << "\n";
    cout << "--------------------------" << "\n";
    int *p_number3{new int{86}};
    int *p_number4{p_number3};
    cout << "p_number3 - " << p_number3 << " - " << *p_number3 << "\n";
    cout << "p_number4 - " << p_number4 << " - " << *p_number4 << "\n";
    //  Deleting p_number3
    delete p_number3;
    //  p_number4 points to deleted memory. Dereferncing it will lead to undefined behaviour: Crash/ garbage or whatever
    cout << "p_number4(after deleting p_number3) - " << p_number4 << " - " << *p_number4 << "\n";
    

    //  2. 
    cout << "--------------------------" << "\n";
    cout << "Initialize your pointers Immediately upon declaration" << "\n";
    cout << "--------------------------" << "\n";
    cout << "Solution1 : " << "\n";
    int *p_number5{};
    int *p_number6{new int{56}}; // int *p_number5{nullptr}-6;
    //  Check for nullptr before use 
    // cout << "*p_number6 : " << *p_number6 << "\n"; for null cases 
    if(p_number6!= nullptr){
        cout << "*p_number6 : " << *p_number6 << "\n";
    }
    cout << "--------------------------" << "\n";
    cout << "Solution 2 : \n Right after you call delete on a pointer, remember to reset the pointer to nullptr to make it CLEAR it doesn't point anywhere  " << "\n";
    cout << "--------------------------" << "\n";
    int *p_number7{new int{82}};
    // use the pointer however you want 
    cout << "p_number7 - " << p_number7 << " - " << *p_number7 << "\n";
    delete p_number7;
    p_number7 = nullptr; // Reset the pointer 
    // Check for nullptr before use 
    // cout << "*p_number7 : " << *p_number7 << "\n"; if we delete the pointer 
    if(p_number7!=nullptr){
        cout << "*p_number7 : " << *p_number7 << "\n";
    } else {
        cout << "Invalid memory access!" << "\n";
    }
    cout << "--------------------------" << "\n\n";
    cout << "Solution3 : For multiple pointers pointing to the same address, Make sure there is one clear pointer (master pointer ) That owns the memory (responsible for releasing when necessary), other pointers should only be able to dereference when the master pointer us valid " << "\n";
    int *p_number8{new int{382}}; // Let's say p_number8 is the master pointer 
    int *p_number9{p_number8};
    //  Dereference the pointers and use them
    cout << "p_number8 - " << p_number8 << " - " << *p_number8 << "\n";
    if(!(p_number8 == nullptr)){ // only use slave pointers when master pointer is valid
        cout << "p_number9 - " << p_number9 << " - " << *p_number9 << "\n";
    }
    delete p_number8; // Master releases the memory  
    p_number8 = nullptr;
    if(!(p_number8==nullptr)){ // Only use slave pointers when master pointer is valid
        cout << "p_number9 - " << p_number9 << " - " << *p_number9 << "\n";
    } else {
        cerr << "WARNING :Trying to use an invalid pointer " << "\n";
    }
    return 0; // 11:24:20 
}
//  12-06-22
/* When 'New' fails 
In some rare cases, the 'new' operator will fail to allocate dynamic memory frim the heap. When that happenes, and you have no mechanism in place to handle that failure, an exception will be thrown and your program will crash. BAD!
     'new' fails very rarely in practice and you'll see many program that assume that it always works and don't check for memory allocation failure in any way. Depending on your application, failed memory allocations can be very bad and you need to check and handle them.

    {1. Simulating memory allocation failure 

     Try to allocate a insanely huge array in one go 
     Unhandled new failure : Crash}

    2. Checking for failed memory allocations
        - Through the exception mechanism
        - The std::nothrow setting 

        The exception mechanism 

        - Handling the exception 
            - Handle the problem in a way that makes sense for your application. For example if you were trying to allocate memory to store color information for your application, and allocation fails, you colud opt for showing some feedback message to the user, and rendering your app in black/white.
            ..
        3. std::nothrow


*/
#include<iostream>
int main(){ 
    // 1. Simulating memory allocation failure.....
    int* lots_of_ints1{new int[100000000000000000]}; // may give an error about exceeding array size.
    // Use a huge loop to try and exhaust the memory capabilites of your system. When new fails, your program is going to forcefuly terminate.
    for(size_t i{};i<10000000; ++i){
        int* lots_of_ints2{new int[10000000]};
    }
    for(size_t i{};i<100; i++){
        try{
            int* lots_of_ints3 {new int[10000000]};
        } catch(std::exception& ex){
            std::cout << "Cought exception oureselves : " << ex.what() << "\n";
        }
    }
    for(size_t i{0}; i<100; i++){
        try{
            int * data{new int[1000000]};
        }catch (std::exception& ex){
            std::cout << " Cought exception oueselve : " << ex.what() << "\n";
        }
    }
    //  std::nothrow : ideal if you don't want exception thrown when new fails
    for(size_t{}; i<100000000000; i++){
        int* lots_of_ints4 {new(std::nothrow)int[10000000]};
        if(lots_of_ints4 == nullptr){
            //  Don't try to dereference and use lots_of_ints4 in here you'll get UB. No memory has really been allocated here It failed and returened nullptr because of the std::nothrow setting 
            std::cout << "Memory allocation failed " << "\n";
        } else {
            std:::cout << "Memory allocation succeeded" << "\n";
        }
    }
     // std::nothrow
    for(size_t i{0}; i<100; i++){
        int * data = new(std::nothrow) int [10000000];
        if(data!=nullptr){
            std::cout << "Data allocated "  << i << "\n";
        } else {
            std::cout << "Data allocation failed " << i  << "\n";
        }
    }
    return 0;
} // null ptr...11:38:40
/* Null Pointer Safety 
     Making sure you are working with pointers containing valid memory addresses
*/
#include<iostream>
int main(){
    // Verbose nullptr check
    int *p_number{}; // Initialized to nullptr
    p_number = new int(7);
    if(!(p_number==nullptr)){
        std::cout << "p_number points to a VALID address : " << p_number << "\n";
        std::cout << "*p_number : " << *p_number << "\n";
    } else {
        std::cout << "p_number points to an INVAILD address ..." << "\n";
    }
    delete p_number;
    nullptr;
     std::cout << "---------------------" << "\n";
    //  Compact nullptr check
    if(p_number){
        std::cout << "p_number points to a VALID address : " << p_number << "\n";
        std::cout << "*p_number : " << *p_number << "\n";
    } else {
        std::cout << "p_number points to an INVALID address : " << "\n";
    }
    std::cout << "---------------------" << "\n";
    std::cout << "Calling delete on a pointer containing nullptr" << "\n";
        //  Calling delete on a nullptr is OK
    int *p_number1{};
    delete p_number1;  // This won't cause any problem if p_number1 contains nullptr
    // So no need to overdo something like 
    if(p_number1){
        delete p_number1;
        p_number1=nullptr;
    }
     std::cout << "---------------------" << "\n";
    return 0;
} // 11:45:21 Memory leaks 

// 29-06-22
/* Memory Leak
     Whenn we loose access to memory that us dynamically allocated 
        Reassignment of stock address to active dynamically address  pointer 
        //  pointer in local scope  
#include<iostream>
int main(int argc, char **argv){
    // .....
    {
        int *p_number2{new int{67}};
    }
    // memory with int{57} leaked.
    return 0;
}
*/
#include<iostream>
using namespace std;
int main()
{
    int *p_number{new int{56}}; // Points to some address, let's call that address1
    //  Should delete and reset here
    int number{47}; /// Lives at address2
    p_number = &number; // Now p_number points to address2, but address1 is still in use by our program. BUt our program has lost access to that memory location. Memory has been leaked.
    cout << "---------------------" << "\n\n";
    //  Double allocation 
    int *p_number1{new int{55}};
    //  use the pointer 
    //  Should delete and reset here.
    p_number1 = new int{44}; // Memory with int{55} leaked.
    delete p_number1;p_number1=nullptr;
    cout << "--------------------" << "\n\n";
    //  Nested scope with dynamically allocated memory 
    {
        int *p_number2{new int{46}};
    }
    // Memory with int{46} leaked.
    cout << "--------------------" << "\n";
    return 0;
} // 11:55:20 

/* Dynamic Arrays -
        Arrays allocated on the heap with the new operator. can alse use the std::nothrow version of new  
*/
#include<iostream>
using namespace std;
int main(){
    // Array dynamic allocation
    /*const*/ size_t size{10};// Different ways you can decLare an array dynamically and how they are initialized 
    double *p_salaries{new double[size]}; // salaries array will contain garbage values
    int *p_students{new(std::nothrow)int[size]{}}; // all values initialized to 0
    double *p_scores{new(std::nothrow)double[size]{1,2,3,4,5}}; // Allocating memory space for an array of size double vars. First 5 will be initialized with 1,2,3,4,5 and the rest will be 0's
    cout << " --------------"  << "\n";
    //  nulltr check and use the allocation array 
    if(p_scores){
        //  Print out elements. can use regular array access notaion, or pointer arithmatic
        for(size_t i{};i<size;i++){
            std::cout << "Values: " << p_scores[i] << " : " << *(p_scores+i) << "\n";
        }
    }
    // Releasing memory [Array version]
    delete[] p_scores;
    p_scores=nullptr;

    delete[] p_salaries;
    p_salaries=nullptr;

    delete[] p_students;
    p_students=nullptr;
    cout << "-------------" << "\n\n";
    cout << "Static Arrays vs dynamic arrays" << "\n";
    int scores[10]{1,2,3,4,5,6,7,8,9,10};
    cout << "scores size : " << std::size(scores) << "\n";
    for(auto s : scores){
        cout << "value : " << s <<  "\n";
    }
    int* p_scores1 = new int[12]{1,2,3,4,5,6,7,8,9,10,11,12}; // Lives on the heap. 
    // cout << "p_scores1 size : " << std::size(p_scores1) << "\n";
    for(auto p : p_scores1){
        cout << "value : " << p <<  "\n";
    }
    // cout << "Pointers and arrays are different" << "\n";
    // //  Pointer initialized with dynamic arrays are different from arrays :  std::size doesn't work on them, and they don't support range based for loops
    // double  *temperatures = new double[size]{10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0,90.0,100.0};
    // //  std::cout << "std::size(temperatures) : " << std::size(temperatures) << "\n"; // Error 
    // // Error : temperatures doesn't have array properties that are needed for the range based for loops to work.
    // for(double temp : temperatures){
    //     std::cout << "temperatures : "  << temp << "\n";
    // }
    // //   we say that the dynamically allocated array has decayed into a pointer
    return 0;
} // 12:11:33

// References
    int     var        0x12ab       33
    var_alias
//  12:11:45
// Declaring and using references



