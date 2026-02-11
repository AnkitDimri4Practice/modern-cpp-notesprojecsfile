1. Array as [Abstract Data Type - ADT]
    - Representation of data and set of Operations on data.
    - Data Representation is defined by complier 
            > Array space (Memory allocation - static or dynamic) 
            > Size (maximum number of elements)
            > Length (number of elements)         
    - Operations have to be defined by us.
        - 
            Display()
            Add(x)/Append(x)
            Insert(index, x)
            Delete(index) delete[] A
            Search(x)
            Get(index)
            Set(index, x)
            Max()/Min()
            Reverse()
            Shift()/Rotate()

The code you provided is an example of creating an Array class and its methods
The class has a private integer pointer A to hold the elements of the array, size to hold the size of the array and length to hold the number of elements in the array.
The constructor takes an integer size as an argument and allocates memory for A dynamically using the new keyword.
The create() method initializes the first length elements of the array with the value 10.
The display() method prints the elements of the array to the console.
The ~Array() is the destructor of the class which is automatically called when the object is destroyed or goes out of scope. It deletes the dynamically allocated memory for the array using the delete[] keyword.
This code does not seem to have any problem or logical error. It is just a basic implementation of an Array class in C++.

#include<iostream>
using namespace std;
class Array{
    private: // here we define the data memeber 
        int *A; // the pointer who point to the array 
        int size;  
        int length;
    public: // lets define the function
    //Constructor 
        Array(int size){ // for constructor , and we'll give the size of the array 
            this->size= size; //the size variable for the current object will be initialized to the given size
            A=new int[size]; // lets create the array 
        }// this array object will be the pointer type.means it will be created in the heap memory. when we use pointer type object.it create in heap memory. and we don't use this . operator . we use -> this operator 
        void create(){ // now we'll define the constructor . it not create the array . this will declare the specific amount of memory in the main memory as per the size 
            length=5; // this length should always be less than the size of the array 
            for(int i{0};i<length;i++){
                A[i]=10; 
            }
        }
        void display(){
            cout << "\n\nThe array elements are ";
            for(int i{0};i<length;i++){
                cout << A[i] << " ";
            }
        }// since when ever we create the array & allocate some memory . we also have to release the memory. when the work of this array object will be over the memo who declare in 11 line .that memo will be automatically deleted .that purpose we use something called destructor :
        //  is a method .which is having same name as that of the class . and it is also automatically called when the object is deleted
        // Destructor
        ~Array(){
            delete[] A;
            cout << "\nThe array is destroyed! \n\n";
        }
};
int main(){
    Array arr1(10);
    arr1.create();
    arr1.display();
    return 0;
}


// New way to write the same code 
#include<iostream>
using namespace std;
class Array{
    private:
    int *A;
    int size;int length;
    public:
    Array(int size){
        this->size = size;
        A = new int[size];
    }
    void Create(){
        length = 10;
        int val{10},p;
        cout << "The elements are...\n";
        for(int i{0};i<length;i++){
            A[i] = 20;
            p = A[i] + val++;
            cout << p  << " ";
        }
    }
    ~Array(){
        delete[] A;
        cout << "\nThe Array is destroyed!\n\n";
    }
};
int main(){
    Array a(10);
    a.Create();
    return 0;
}

 2.
Inserting in Array : - 
    - Create an array :
        - size = 10;
        - Length = 6;
            - for(int i{0}; i<length;i++){
                cout << A[i];
            }
        - Add(x)/Append(x) - Adds element at end 
            A[length] = x;
            length++;
            Time=O(1)
        - Insert(index,x)- Adds elements at given index 
            - insert(4,15)
            for( i = lentgth; i < index; i--){
                A[i] = A[i-1];
            }
            A[index] = x;
            length++;
            
            Time = O(n)

// Array_insertion 
#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array a){
    cout << "The Array elements are : ";
    for(int i{0};i<a.length;i++){
        cout << a.A[i] << " ";
    }
}
void append(struct Array *a, int x){
    if(a->length < a->size){
        a->A[a->length] = x;
        a->length++;
    }
}
void insert(struct Array *a, int index, int x){
    if(index>=0 && index<a->length){
        for(int i{a->length}; i>index; i--){
            a->A[i] = a->A[i-1];
        }
        a->A[index] = x;
        a->length++;
    }
}
int main(){
    struct Array a = {{1,2,3,4,5,6,9},10,7}; // 10 is size and 7 is the length of the array 
    cout << "\n\nThe initial array is : \n";
    display(a);

    append(&a, 100);
    cout << "\nArray after appending 100 : \n";
    display(a);

    insert(&a, 0 , 200); // 0 index value 
    cout << "\nArray after insertion of 200 : \n";
    display(a);
    return 0;
}


// 3.
Deleting from Array :-
        Create an array: 
    - Size - 10 
    - Length - 7
        
        - delete(index)-Deletes elements from given index
            Delete(3)
                x = A[index];
                for(i = index; i<length-1; i++){
                    A[i] = A[i+1];
                } 
                length--;           Time = O(n)

#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    for(int i= 0; i<arr.length; i++){
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}
int Delete(struct Array *arr, int index){
    int x = 10;
    int i;
    if(index >=0 && index<arr->length){
        x = arr->A[index];
        for(i = index; i<arr->length; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
int main(){
    struct Array arr1 = {{1,2,3,4,5},10,5};
    cout << "The delete element is : " << Delete(&arr1,1) << "\n";
    display(arr1);
    return 0;
}

//4.    
> Seraching in Array : - 
    - Linear Search 
            - Size = 10
            - Length = 10
            - Key = 5
            - All the elements of array are checked one by one until end is reached or the key element is found.
            - Returns the index of key element.

            Linear Search - Code
            for(i = 0;i<length; i++){
                if(key==A[i])
                    return 
            }
            Linear Search - Time complexity 
                - for(i=0;i<length;i++){            Time = O(n) Worse case 
                    if(key==A[i])                       = O(1) Best case
                        return i;
                }
                return -1;
            
            - Linear Search - Imporiving time complexity 
                - Method 1 (Transposition) - Every Time the key element is searched, move it one step forward.
                    for(i = 0; i<length;i++){
                        if(key==A[i]){
                            swap(A[i],A[i-1]);
                            return i;
                        }
                    }
                    return -1;
            
            - Linear Search 
                - Method 2(Moved to head)- Every time the key element is searched, swap it with the first element.
                    for(i=0;i<length;i++){
                        if(key == A[i]){
                            swap(A[i],A[0]);
                            return i;
                        }
                    }   
                    return -1; 

#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    for(int i = 0; i<arr.length;i++){
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}
int LinearSearch(struct Array *arr, int key){
    for(int i=0;i <arr->length; i++){
        if(key==arr->A[i]){       
            return i;
        }
    }
    return -1;
}
int main(){
    struct Array arr={{1,2,3,4,5},10,5};
    cout << "The Searched element is found at position : " << LinearSearch(&arr, 4);
    return 0;

}

// 5. Binary Search : - 
    -
    - Necessary condition :-
    Array of elements must be sorted
        Approach :
            - Always check for the key elements in the middle, and then split the list into two parts.
            - Three index variables are used - l,h,m.
            - l=0
            - h=n-1
            - m=(l+h)/2
            - Example [10,20,30,40,50,60,70]
        Binary Search - Algorithm (Iterative Version)
            Algorithm BinSearch(l,h,key){
                while(l<h){
                    mid = (l+h)/2
                    if(key == A[mid])
                        return mid;
                    else if(key<A[mid])
                        h = mid-1
                    else 
                        l = mid+1
                }
                return -1
            }
        Binary Search - Algorithm(Recursive version){
            if(l<=h){
                mid = (l+h)/2
                if(key == A[mid])
                    return mid;
                else if(key<A[mid])
                    RBinSearch(l,mid-1,key);
                else
                    RBinSearch(mid+1,h,key);
            }
            return -1;
        }
    - Binary Search - Time Complexity 
         Worst Case time - O(log n)
         Best case time - O(1)
-
    
#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++){
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}
int BinarySearch(struct Array arr, int key){
    int l, mid, h;
    l = 0;
    h = arr.length-1;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h = mid-1;
        }
        else {
            l = mid +1;
        }
    }
    return -1;
}
int main(){
    struct Array arr = {{10,20,30,40,50},5,5};
    cout << "The index of the key element is - " << BinarySearch(arr,50);
    return 0;
}

6. Get, Set, Avg, Max, functions On Array : 
    - Get(index) : 
        - Returns element at a given index 
        - check index is valid or not. 

            if(index>=0 && index < length){
                return A[index]
            } 
        Time = O(1)  Time complexity is constent 

    - Set(index) : 
        - Replace element at a given index
        
            if(index>=0 && index < length){
                A[index] = x;
            } 
        Time = O(1) 

     - Max() :  It'll return the maximum elements from the whole array 
        - Returns the maximum element 
        int max = A[0]
        for(int i = 0; i<length; i++){    
            if(A[i]>max)
                max = A[i];
        }
        return max

        - Time = O(n)

> In lecture no.47 (under Array adt) , my question is how would we know when to use pointers in the functions like for example in get function we used 'struct Array arr' and in set function, we have used 'struct Array *arr'
The usage of pointers in the functions depends on whether the function needs to modify the original array or not. When we use 'struct Array arr' in the get function, we are passing the array by value, which means a copy of the array is passed to the function, and any modifications made to the array inside the function will not affect the original array. On the other hand, when we use 'struct Array *arr' in the set function, we are passing the array by reference (using a pointer), which means the function can directly access and modify the original array. The decision to use pointers depends on the specific requirements of the function and whether we want to modify the original array or work with a copy of it. If we need to modify the original array, we use pointers to pass it by reference. If we don't want to modify the original array, we can pass it by value.

Pointers are used in the set function to pass the array by reference, allowing direct modification of its elements. On the other hand, in the get function, no pointers are used as the array is passed by value, meaning modifications within the function do not affect the original array. This distinction is made based on whether the function requires read-only access or if it needs to modify the array directly.

#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size,len;
};

void display(struct Array arr)
{
    for(int i=0;i<arr.len;i++)
    {
        cout<<" "<<arr.A[i];
    }
    cout<<endl;

}
void swap(int *x,int *y )//pass by reference-use pointers
{
    int temp=*x;
    *x=*y;
    *y= temp;
}

int get(struct Array arr,int index)
{
    if(index>=0 && index<arr.len)
    {
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr, int index,int x)
{
    if(index>=0 && index<arr->len)
    {
        arr->A[index]=x;
    }
}
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.len;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=0;i<arr.len;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}
int sum(struct Array arr)
{
    int tot=0;
    for(int i=0;i<arr.len;i++)
    {
        tot+=arr.A[i];
    }
    return tot;
}
float avg(struct Array arr)
{
     return (float)sum(arr)/arr.len; //typecasting to get value in float format
}
int main()
{
    struct Array arr1={{1,2,3,4,5},5,5};
    cout<<"The array elements are:"<<endl;
    display(arr1);
    cout<<"The element at index 2 is: "<<get(arr1,2)<<endl;
    set(&arr1,2,20);
    display(arr1);
    cout<<"Max element of the array is: "<<max(arr1)<<endl;
    cout<<"Min element of the array is: "<<min(arr1)<<endl;
    cout<<"Sum is: "<<sum(arr1)<<endl;
    cout<<"Avearge is: "<<avg(arr1)<<endl;
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int index = 2; // Insert at index 2
    int value = 100; // Value to insert
    arr.insert(arr.begin() + index, value);
    index = 1; // Delete element at index 1
    arr.erase(arr.begin() + index);   
    for (int num : arr) {   // Display the updated array
        cout << num << " ";
    }
    return 0;
}
