//  12-05-22
/* Array
How to declare ur array....
Declaring and reading from an Array 
*/
#include<iostream>
#include<array>
int main(){
    int scores[10]; // An array storing 10 integers
    // Reading values 
    std::cout << "1-----------------------" << "\n";
    std::cout << "\n" << "regular out score values (manually) : " << "\n";
    std::cout<<"scores[0] : " << scores[0] << "\n";
    std::cout<<"Scores[1] : " << scores[1] << "\n";
    std::cout<<"Scores[7] : " << scores[7] << "\n";
    std::cout<<"Scores[8] : " << scores[8] << "\n";
    std::cout<<"Scores[9] : " << scores[9] << "\n";
    //  reading past nounds of your array : BAD!
    //  It's going to read out something you didn't put there. 
    std::cout<<"Scores[10] : " << scores[10] << "\n";
    std::cout << "2-----------------------" << "\n";
    //   Can read through a loop
    // Looping through an array
    for (size_t i{0};i<10;i++){
        std::cout << "Score[" << i << "] : " << scores[i] << "\n";
    }

    std::cout << "3-----------------------" << "\n";
    // Writing data into an array
    scores[0]=20,scores[1]=21,scores[2]=22;
    // Writting out of bounds. BAd!
    scores[22]=300;
    std::cout<<"\n"<<"Manually writting data in array : " << "\n";
    for(size_t i{0}; i<10; ++i){
        std::cout<<"Scores[" << i << "] : " << scores[i] << "\n";
    }

    std::cout << "4-----------------------" << "\n";
    // Writting data with a loop 
    // int scores[10]; // An array storing 10 integers
    std::cout<<"Writting data in array with loop : " << "\n";
    // Write data 
    for(size_t i{0}; i<10; ++i){
        scores[i] = i*3;
    }
    //  Read data out 
    for(size_t i{0};i<10;++i){
        std::cout<<"Scores[" << i << "] : " << scores[i] << "\n";
    }

    std::cout << "-5----------------------" << "\n";
    //  Initialize the array at declaration
    //  Declare and Initialize at the same time 
    std::cout << "\n" << "Declare and Initialize at the same time : " << "\n";
    double salaries[5] {12.4, 4.5, 23.34, 45.54, 43.5};
    for(size_t i{0};i<5;++i){
        std::cout << "Salary["<<i<<"] : "<<salaries[i]<<"\n";
    }
    std::cout << "6-----------------------" << "\n";
    // Array Initialization : Omitting element
    // If you don't initialize all the elements, those you leave out are initialized to 0
    std::cout<< "Leaving out some elements un- initialized : " << "\n";
    int families[5]{12,7,5};
    for(size_t i{0}; i<5; ++i){
        std::cout<<"Familes["<<i<<"] : " << families[i] << "\n";
    }
    std::cout << "7-----------------------" << "\n";
    //  Array declaration : Omit size
    //  Omit the size of the array at declaration
    int class_size[] {12,23,34,45,32,32,45,32,34};
    for(auto value : class_size){ // range based for loop
        std::cout << " value : " << value << "\n";
    }
    std::cout << "8-----------------------" << "\n";
    // Constant arrays, can't be modified.
    // const int multipliers [] {22,30,16};
    // multipliers[1] = 20; // can't change elements of a const array : Error
    std::cout << "9-----------------------" << "\n";
    //  Operations on data stored in arrays
    //  Sum up scores ARRAY, stored result in sum
    int scores1 [] {23,34,56,66,78,28};
    int sum1{0};
    for(int elements : scores1){
        sum1+=elements;
    }
    std::cout << "Score sum : " << sum1 << "\n";
} 
// 9:15 hr start 
#include <iostream>
#include <array>
int main()
{
    //  Size of An Array 
    int scores[]{23, 34, 54, 56, 56, 87};
    //  Can get the size with std::size'
    // int count {std::size(scores)};
    std::cout << "Scores size : " << std::size(scores) << "\n";
    for (size_t i{0}; i<std::size(scores); ++i){
        std::cout << "Scores[" << i << "] : " << scores[i] << "\n";
    }
    std::cout << "---------------" << "\n";
    std::cout << " (Array size with sizeof) " << "\n";
    std::cout << "---------------" << "\n";
    std::cout << "Size of scores : " << sizeof(scores) << "\n";
    std::cout << "size of scores[0] : " << sizeof(scores[0]) << "\n";
    std::cout << "score item count : " << (sizeof(scores)/sizeof(scores[0])) << "\n";
    size_t count {sizeof(scores)/sizeof(scores[0])};
    std::cout << "---------------" << "\n";
    std::cout << " printing out array items : " << "\n";
    for(size_t i{0}; i<count; ++i){
        std::cout << "scores[" << i << "] : " << scores[i] << "\n";
    }
    std::cout << "---------------" << "\n";
    std::cout << "looping through an array" << "\n";
    std::cout << "---------------" << "\n";
    std::cout << " using plain old range based for loop " << "\n";
    int scores1[]{73, 34, 55, 57, 59, 80, 48, 34, 26};
    //  Range based for loop :- 
    for(auto score : scores1){
        std::cout << "Score : [" << score << "]\n";
    }
}
//  Array of characters 
#include<iostream>
int main()
{ 
    //  Declare array 
    std::cout <<"---------------" <<  "\n";
    char message [5] {'H', 'e', 'l', 'l', 'o'};
    // Print out the array through looping
    std::cout << "Message : ";
    for(auto c : message){
        std::cout << c << "\n";
    }
    std::cout <<"---------------" <<  "\n";
    std::cout << "size : " << std::size(message) << "\n";
    //  Can also modify elements of the char array 
    std::cout << "--------------------" << "\n";
    std::cout << "Modify array data : " << "\n";
    message[1] = 'a';
    // Print out the array 
    std::cout << "Message : ";
    for(auto c: message){
        std::cout << c;
    }
    std::cout<< "\n" << "------------------" << "\n";
    std::cout << " Direct print out " << "\n";
    std::cout << "message : " << message << "\n";
    std::cout<< "\n" << "------------------" << "\n";
    // Proper Null termination 
    char message1 []{'H', 'e', 'l', 'l', 'o','\0'}; // garbage character
    std::cout << "message : " << message1 <<"\n";
    std::cout << "size: " << std::size(message1) << "\n";
    std::cout<< "\n" << "------------------" << "\n";
    std::cout << "Auto filled in null characters" << "\n";
    char message2[6]{'H', 'e', 'l', 'l', 'o'};
    std::cout << "Message 2 : " << message2 << "\n";
    std::cout << "Size : " << std::size(message2) << "\n";
    std::cout << "---------------------" << "\n";
    std::cout << "Looks may be deceiving " << "\n";
    char message3[]{'H', 'e', 'l', 'l', 'o'}; // This is not  a c string as there is not null character 
    std::cout << "Message 3 : " << message3 << "\n";
    std::cout << "Size : " << std::size(message3) << "\n"; // Will probavly print some garbage after out hello message 
    std::cout << "-----------------" << "\n";
    std::cout << "Literal C-String " << "\n";
    //  Can also define a literal C string 
    char message4[]{"Hello"}; // An implicit '\0' character is apeended to the end of the string, making it a c string 
    std::cout << "message 4: " << message4 << "\n";
    std::cout << "size :: " << std::size(message4) << "\n";
    //  Can even have spaces between characters 
    char message5[]{"Hello Wolrd!"};
    std::cout << "Message 5 : " << message5 << "\n";
    std::cout << "Size : " << std::size(message5) << "\n";
    std::cout << "----------------" << "\n";
    std::cout << "Arrays of char are special" << "\n";
    //  Can't direct print arrays other than that of chars 
    int numbers[]{1,2,3,4,5,6,7,8,9,0};
    std::cout << "Numbers : " << numbers << "\n";
    std::cout << "-----------------" << "\n";
    int numbers1[] {1,2,3,4,5,6,7,8,9,0};
    //  Read beyond bounds : will read garbadge or crash your program
    std::cout << "Number[12] : " << numbers1[12] << std::endl;
    /* Write beyond bounds. The complier allows it. Nut You don't own the memory at index 12, so other programs may modify it and your program may read bogus data at a later time. or you can even corrupt data used by other parts of your program*/
    // numbers1[1299999]=1000;
    // std::cout << "numbers[1299999] : " << numbers1[1299999] << "\n";
    // after that the  program will be crashed 
}