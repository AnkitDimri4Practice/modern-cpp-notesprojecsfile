/* Understanding differences between C and C++ for
    - IO
    - Variable declaration  
    - Standard Library 
    - Bool
- C++ gives us more flexibility in terms of basic declaration and input / output
- Many C constructs and functions are simplified in C++ which helps to increase the ease of programming 


Module Objectives
    - Understand array usage in C and C++
    - :: vector usage in C++
    - :: string functions in C and String type in C++
1. Arrays & Vectors 
    - Array implementations for fixed size array 
    - Array :: for arbitrary sized array
    - Vectors in C++
2. C- style strings and strings type in C++
    - Concatenation of strings
    - More string operations
    - String.h
    - String class
3. Module summary 
*/
// Fixed sized Array 
#include<stdio.h>
int main(){
    short age[4];
    age[0]=23;age[1]=34;age[2]=65;age[3]=74;
    printf("%d ",age[0]);
    printf("%d ",age[1]);
    printf("%d ",age[2]);
    printf("%d ",age[3]);
    return 0;
}
// NO Difference between array C and C++

#include<iostream>
using namespace std;
int main(){
    short age[4];
    age[0]=23;age[1]=43;age[2]=56;age[3]=67;
    cout << age[0] << " ";cout << age[1] << " ";cout << age[2] << " ";cout << age[3] << " ";
    return 0;
}
// Fixed size large array in C
// cout << "HArd-coded" << "\n";
#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[100],sum=0,i;
    printf("Enter the no of elements : ");
    int n;
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        arr[i]=i;
        sum+=arr[i];
    }
    printf("Array  Sum : %d",sum);
}
// C++
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[100],sum=0,n;
    cout << "Enter no. of elements : ";
    cin >> n;
    for(int i{0};i<n;i++){
        arr[i]=i;sum+=arr[i];
    }
    cout << "\nArray Sum : " << sum << "\n";
    return 0;
}
// using manifest constant 
#include<stdio.h>
#include<stdlib.h>
# define MAX 10000
int main(){
    int arr[MAX],sum=0,i;
    printf("Enter no. of elements : ");
    int count;
    scanf(("%d"),&count);
    for(i=0;i<count;i++){
        arr[i]=i;
        sum+=arr[i];
    }
    printf("Array sum : %d",sum);
}
// C++
#include<iostream>
// #include<algorithm>
# define M 1000 // Max
using namespace std;
int main(){
    int arr[M],sum{0},n;
    cout << "Enter no. of elements : ";
    cin >> n;
    for(int i{0};i<n; i++){
        arr[i]=i;sum+=arr[i];
    }
    cout << "Array sum : " << sum << "\n";
    return 0;
}

/* This can be implemented in C(C++) in the following ways:
- Case 1:
Declaring a large array with size greater than the size given by users in all (most) of the cases
    - Hard-code the maximum size in code.
    - Declare a manifest constant for the maximum size..
Case : 2 using malloc(new[]) to dynamically allocate space at run-time for the array
*/

// Fixed large array : 
#include<iostream>
#include<vector>
# define M 1000 // Max
using namespace std;
int main(){
    vector<int>arr(M); // define-time size 
    int sum{0},n;
    cout << "Enter no. of elements : ";cin >> n;
    for(int i{0};i<n; i++){
        arr[i]=i;sum+=arr[i];
    }
    cout << "Array sum : " << sum << "\n";
    return 0;
}


//  Dynamically managed array size
#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter no. of elements : ");
    int count,sum=0,i;
    scanf("%d",&count);
    int *arr=(int*)malloc(sizeof(int)*count);
    for(i=0;i<count;i++){
        arr[i]=i;sum+=arr[i];
    }
    printf("Array Sum : %d", sum);
}
// malloc allocates space using sizeof

#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout << " Enter the no. of elements : ";
    int count,sum{0};cin >> count;
    vector<int>arr;//define size 
    arr.resize(count); 
    for(int i {0};i<count; i++){
        arr[i]=i;sum+=arr[i];
    }
    cout << "\nArray sum : " << sum << "\n";
    return 0;
} // resize fixes vector size at run-time..


/*  C-style String and string type in C++
        - String manipulation in C and C++
            -  C-string and string.h library
                - C-String is an array of char terminated by NULL
                - C-String is supported by functions in string.h in C Standard library 
            - String type in C++ standard library
                - string is a type
                - With operator (like + for concatenation) it behaves like a built-in type
                - In addition, for funtions from C Standard library string.h can be used in C++ as cstring in std namespace 
*/
//  Concatenation of strings 
#include<stdio.h>
#include<string.h> // needed header string.h
int main(){ // C-string is an arrqy of  characters
    char str[] = {'H','E','L','L','O',' ','\0'};
    char str1[]="World";
    char str2[20]; // str2 must be large to fit the result 
    strcpy(str2,str); // need a copy into str
    strcat(str2,str1); // String concatenation done with strcat funcion 
    printf("%s\n",str2);
}
// In C++
#include<iostream>
#include<cstring>
using namespace std;
int main(void){
    string str1 = "HELLO "; // string is a data-type in C++ standard library 
    string str2="WORLD";
    string str = str1 + str2; // string are concatenated like addition of int
    cout << str;
}
/* MOre operations on strings
    Operator  =  can be used on strings in place of strcpy function in C
    - operator <=, <,>=,> operator can be used on string in place of strcmp function in C
*/
/* String in C and C++ : C++ Standard Library string class 
        - strings are objects that represent sequences of characters 
        - The standard string class provides support for such objects with an interface similar to that of a standard container of bytes, but adding features specifically designed to operate with strings of single-bytes characters
        - The string claass in an instantiation of the basic_string class template that uses char (that is bytes) as its character type, with its default char_traits and allocation types
*/
// and about the more details check the folder modern c++

