// 09-05-22
/* Pillers of any Loop
-->> size_t = Not a type, just  a type clias for some unsigned int representation
Iterator , 
starting point , 
Test(Controls when the loop stops, 
Increment(Decrement), 
size_t --> a representation of some unsigned int for positive number [sizes]
Loop Body)*/
#include<iostream>
int main()
{
    int f;
    // For Loops programme : - 
    for(unsigned int i{}; i<10; ++i){
        std::cout << i << "  ";
    } for(size_t i{0}; i<10; i++){ // other operations in the loop body....
        std::cout<<"i : " << i << ". Double that and you get " << 2*i << std::endl;
    }
    return 0;
}
// 
#include<iostream>
int main(int argc, char **argv){    //  scope Of the iterator
    std::cout << " ------------------" << "\n";
    for(size_t i{0}; i<5; ++i){
        //  i is valid to use within the boundaries of the {} here 
        std::cout << "i is usable here, the value is : " << i << std::endl;
    }
    // If you try to access i here, you'll get an error 
    //  i don't exist in the main function local scope
    std::cout << " ------------------" << "\n";
    // iterator can live outside the loop scope  
    size_t j{};
    for(j; j<5; ++j){ // without using  j :
        std::cout<<"using the j variable from main function local scope : " << j << std::endl;
    }
    std::cout << "Loop done, the value of j is: " << j << std::endl;
    std::cout << " ------------------" << "\n";
    //  Hard coded values are bad
    const size_t COUNT {10};
    for(size_t j{}; j<COUNT;++j){
        std::cout << "The value of j is : " << j << std::endl; 
    }
    std::cout  << sizeof(size_t)<< " ------------------" << "\n";
    return 0; 
}
//  While Loop  
/* Piller of any loop
- Iterator 
- Starting Point
- Test(Controls when the loop stops)
- Increment (Decrement)
- Loop body*/
#include<iostream>
int main()
{
    std::cout << "--------------------------" << "\n"; 
    const unsigned int COUNT{10}; 
    unsigned int i {0}; // size_t i{0}; we can also use this statement
    //  iterator declaration
    while(i<COUNT){ // Test 
        std::cout << "The numbers are : " << i << std::endl;    i++;  // Incrementation  
    }
    std::cout <<  "Loop done!\n-----------------------" << "\n";
    return 0;
}
/*  Do While loop ---> Runs the body then checks
loop with output */
#include<iostream>
int main()
{
    const unsigned int COUNT{10};
    unsigned int i {11}; // Initialization 
    do{
        std::cout << "[" << i << "] : The number is : " << std::endl;   i++; 
    } while(i<COUNT); // Test
    std::cout << " --------------" << "\n";
    const int COUNT{10};
    size_t i{0};
    do{
        std::cout << "The  number is : " << i << std::endl;     i++;
    } while(i<COUNT); 
} 
