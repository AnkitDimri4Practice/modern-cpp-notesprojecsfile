 /* -  Working with variable sized arrays in more flexible with vectors in C++ 
    - String operations are easier with C++ standard library 

        - Sorting in C and C++
            - Bubble Sort
            - USing standard Library 
        - Searching in C and C++
            - using Statndard Library 
        - STL - algorithm - The algorithm Library 
        - Module summary 
*/
//1 Bubble Sort in C and C++ -- Ascending Order : 
#include<stdio.h>
int main(){
    int data[]={73,49,45,60,67},i,s,n=5,temp;
    for(s=0;s<n-1;s++)
        for(i=0;i<n-s-1;i++){
            if(data[i]>data[i+1]){
                temp=data[i];
                data[i]=data[i+1];
                data[i+1]=temp;
            }
        }
        for(i=0;i<5;i++)
            printf("%d ",data[i]);
} 
//1 in C++
#include<iostream>
using namespace std;
int main(){
    int data[]{345,423,25,54,245,543},n{6},temp;
    cout << "\nAscending order : ";
    for(int s{0};s<n-1;s++)
        for(int i{0};i<n-s-1; i++){
            if(data[i]>data[i+1]){
                temp=data[i];
                data[i]=data[i+1];
                data[i+1]=temp;
            }
        }
        for(int i{0};i<6;i++)
            cout << data[i] << " ";
}
//2 using sort from standard library -- Descending order 
#include<stdio.h>
#include<stdlib.h> //qsort function
// Compare Function pointer 
int compare(const void *a, const void *b){ // Type unsafe -- void * for to int char or defined element type
    return(*(int*)a < *(int*)b); // cast needed
}
int main(){
    printf("\nDescending order : ");
    int data[]={23,52,13,73,17,73,82};// start ptr.., #element, size, func. ptr.
    qsort(data,7,sizeof(int),compare); // quick sort
    for(int i=0;i<7;i++)
        printf("%d ",data[i]);
} 
// sizeof(int) and compare function passed to qsort
//2 compre function is type unsafe & needs complicated cast

#include<iostream>
#include<algorithm> //sort function 
using namespace std;
bool compare(int i, int j){ // Type safe 
    return (i>j); // NO cast needed
}
int main(){
    int data[]{23,41,67,25,73,82,28}; // Start ptr., end ptr., func. ptr. 
    cout << "\nDescending Order : ";
    sort(data,data+7,compare);
    for(int i{0};i<7;i++)
        cout << data[i] << " ";
}
/*- Only compare passed to sort. NO size is needed.
- Only size is inferred from the type int of data 
- Compare function is type safe & simple with no cast */

//2 Using default sort of algorithm
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cout << "\nAscending Order : ";
    int data[]{23,45,42,62,75,79};
    sort(data,data+6);
    for(int i{0};i<6;i++)
        std::cout << data[i] << " ";
} // Ascn Order 
// - Sort using the default sort function of algorithm library which does the sorting in ascending order only
// - No compare function is needed.

//3  - Searching in C and C++ - Binary Search 
#include<stdio.h>
#include<stdlib.h> // bsearch function
//compare function pointer 
int compare(const void * a, const void * b){ // type unsafe
    if(*(int*)a < *(int*)b) // cast needed
    return -1;
    if(*(int*)a == *(int*)b) // cast needed
    return 0;
    if((*(int*)a > *(int*)b)) // cast needed
    return 1;
}
int main(){
    int data[]={12,3,1,4,5,6,2},k=9;
    if(bsearch(&k,data,7,sizeof(int),compare))
        printf("found!\n");
    else
        printf("not found\n");
}
// Compare function is type unsafe & needs complicated cast
#include<iostream>
#include<algorithm> // binary_search function 
using namespace std;
int main(){
    int data[]{10,2,3,44,5,6,7},k{2};
    if(binary_search(data,data+7,k))
        cout << "found!\n";
    else 
        cout << "Not Found\n";
}

/* STL : algorithm - The algorithm Library 
    - Replace element in an array
    - Rotates the order of the elements 
*/
// Replace.cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int data[]={1,2,3,4,5};
    replace(data,data+5,3,7);
    for(int i{0};i<5;i++)
        cout << data[i] << " ";
    return 0;
}

// Rotate.cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int data[]{1,2,3,4,5,6};
    rotate(data,data+2,data+6);
    for(int i{0};i<6;i++)
        cout << data[i] << " ";
        return 0;
}
/* - Flexibility of defining customised sort algorithms to be passed as parameter to sort and search functions defined in the algorithm library.
- Predefined optimised versions of these sort and search functions can also be used 
- There are a number of useful functions like rotate, replace, merge,swap,remove. etc in algorithm library .
*/ 
/// Extra programe 
#include<iostream>
using namespace std;
# define NO_OF_CHARS 256
class D{
    public :
    void D1(char *s,int *c){
        int i;
        for(i=0;*(s+i);i++)
        c[*(s+i)]++;
    }
    void D2(char *s){
        int *c = (int*)calloc( NO_OF_CHARS,sizeof(int));
        D1(s,c);
        for(int i=0;i<NO_OF_CHARS;i++)
            if(c[i]>1)
                printf("%c\t\t\t%d \n",i,c[i]);
        free(c);

    }
};
int main(){
    D a;
    char s[]="I want to destroy you..";
    cout << "\nThe duplicate character in this string : ";
    cout << "\nCharacter\tCount\n";
    a.D2(s);
    return 0;
}