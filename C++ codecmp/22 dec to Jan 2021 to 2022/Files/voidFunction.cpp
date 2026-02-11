// coordinate for #D and area and circumference of the circle 
#include<cmath>
#include<iostream>
using namespace std;
void Coordinate_3D(int r){
    float PI = float(22)/float(7);
    float area,c;
    area = PI*r*r; 
    c=2*PI*r;
    cout << "Circumference = " << c << "\n" << "Area = " << area << "\n"; 
}
int main()
{
    int radius,x1,x2,x3,x4,y1,y2,y3,y4;
    float area1,a,b,c,d,s;
    cout << "please enter the radius of the circle ";
    cin >> radius;
    Coordinate_3D(radius);
    cout << "please enter the 1st points of x and y coordinate respectively ";
    cin >> x1 >> y1;
    cout << "please enter the 2nd points of x and y coordinate respectively ";
    cin >> x2 >> y2;
    cout << "please enter the 3rd points of x and y coordinate respectively ";
    cin >> x3 >> y3;
    cout << "please enter the 4th points of x and y coordinate respectively ";
    cin >> x4 >> y4;
    a=sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
    b=sqrt(pow((x2-x3), 2) + pow((y2-y3), 2));
    c=sqrt(pow((x3-x4), 2) + pow((y3-y4), 2));
    d=sqrt(pow((x4-x1), 2) + pow((y4-y1), 2));
    area1=sqrt(s*(s-a)*(s-b)*(s-c)*(s-d));
    s = (a+b+c+d)/2;
    cout << "A = " << a << "\n" << "B = " << b << "\n" << "C = " << c << "\n" << "D = " << d << "\n" << "Area = " << area1 << "\n" << "S = " << s << "\n"; 
    return 0;
}

// the Greatest Number find
#include<cmath>
#include<iostream>
using namespace std;
int greatest(int x, int y, int z){
    if(x>=y){
        if(x>=z){
            return x;
        } else {
            return z;
        }
    } else {
        if(y>= z){
            return y;
        } else {
            return z;
        }
    }
}
int main()
{
    int a, b, c, g;
    cout << "enter the value of a b and c";
    cin >> a >> b >> c;
    g = greatest(a,b,c);
    cout << " Greatest number is " << g << "\n";
    g = greatest(1087,99,68);
    cout << " Greatest number is " << g << "\n";
    g = greatest(197,11961,19179);
    cout << " Greatest number is " << g << "\n";
    return 0;
}

// Raised to the power of n: x^y: 
#include<iostream>
#include<cmath>
using namespace std;
int power_m(int a, int b);
int main()
{
    int x, y, ans;
    cout << "\nEnter the value of x and y , such that x^y " << "\n\n";
    cin >> x >> y;
    ans = power_m(x,y);
    cout << "Power of = " << x << " raised to " << y << " is :: " << ans << "\n\n"; 
    return 0;
}
int power_m(int a, int b){
    int outpt = 1;
    for(int i = 0; i<b;i++){
        outpt *= a;
    }
    return outpt;
}

// swap prog

#include<iostream>
using namespace std;
void swap_m(int, int);
int x = 11;
//global scope
int main()
{// scope 
    int a,b;
    cout << "Enter the value of a and b : ";
    cin >> a >> b;
    swap_m(a,b);
    cout << " Outside Fn, A = " << a << "\n" << " B = " << b << "\n";
    cout << "X is " << x << "\n";
    return 0; 
}
// scope int
void swap_m(int a, int b){
    int temp;
    temp = b;
    b=a;
    a=temp;
    cout << " inside Fn, a is : " << a << " and b is " << b << "\n"; 
}

// swapping programe: in case for pointer
#include<iostream>
using namespace std;
void swap_m(int*, int*);
int* testing_m(int*,int*);
int x = 11;

int main()
{
    int a,b;
    cout << "Enter the value of a and b : ";
    cin >> a >> b;
    swap_m(&a,&b);
    cout << " Outside Fn, A = " << a << "\n" << " B = " << b << "\n";
    cout << " X is " << x << "\n";
    return 0; 
}
void swap_m(int *a, int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a=temp;
    cout << " inside Fn, a is : " << *a << " and b is " << *b << "\n"; 
}

// array for assending and decending order 
#include<iostream>
using namespace std;
void swap(int*, int*); //.. our swap function.
void sortarray(int*, int); // primary sorting fn
int main() // write a function to sort a array
{
    int n;// size of array
    cout << "Size of the array = ";
    cin >> n;
    int arr[n];
    cout << "\nplease enter all the elements of the array = ";
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    cout << "\nSorting ------- \n";
    sortarray(arr, n); // passes address of first elements of array
    cout << "\nArray is sorted now -- \n";
    for(int i = 0; i<n; i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
    return 0;
}
void sortarray(int* arr, int size){ // selection sort
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j<size; j++){
            if(arr[i]<=arr[j]){
                continue;
            } else {
                swap(arr+i, arr+j);// ptr+2 , pt++, ptr++
            }
        }
    }
    return;
}
void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

//  maximum number :
#include<string>
#include<iostream>
using namespace std;
int max_two(int x, int y){
    if(x>=y){
        return x;
    } else {
        return y;
    }
};
int main()
{
    int n1,n2,T;
    cout << "\n\nenter the value of n1 and n2 ";
    cin >> n1 >> n2;
    T = max_two(n1,n2);
    cout << "\nThe Maximum number = " << T << "\n";
    return 0;
}

// sum of all elements in array
#include<iostream>
using namespace std;
int main()
{
   int limit,sum  = 0;
   cout << "Enter limit of the array " << "\n";
   cin >> limit;
   int *element = new int[limit];
   cout << "Entered Array elements are " << "\n";
   for(int i = 0; i<limit; i++){
      cin >> *(element + i);
   }
   for(int i = 0; i<limit;i++){
      sum  += *(element+i);
   }
   cout << "Sum of array elements is " << sum << "\n";
  
   return 0;
}

#include<iostream>
using namespace std;
void swap(int*, int*);
void sortarray(int*, int);
int main()
{
   int n;
   cout << "enter the size of the array : ";
   cin >> n;
   int arr[n];
   cout << "please enter all the elements of the array ";
   for(int i = 0; i<n;i++){
      cin >> arr[i];
   }
   cout << "Sorting .....";
   sortarray(arr, n);
   cout << " array is sorted now...";
   for(int i = 0; i<n; i++){
      cout << arr[i] << "\t";
   }
   cout << "\n";
   return 0;
}
void sortarray(int* arr, int size){
   for(int i = 0; i<size-1; i++){
      for(int j = i+1;j<size;j++){
         if(arr[i]<= arr[j]){
            continue;
         } else {
            swap(arr+i, arr+j);
         }
      }
   }
   return;
}
void swap(int* a, int* b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
   return;
}

// Empolyee structure
#include<iostream>
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
    cout << "Enter total number of employee " << "\n";
    cin >> n;
    Employee record[n];
    for(int i = 0; i<n;i++){
        cin >> record[i].name >> record[i].age >> record[i].salary >> record[i].performance;
        cout << "\nEmployee Name = " << record[i].name;
        cout << "\nEmployee Age = " << record[i].age;
        cout << "\nEmployee Salary = " << record[i].salary;
        cout << "\nEmployee Performance = " << record[i].performance << "\n";
    } 
    return 0;
}

//adding complex
#include<iostream>
using namespace std;
struct complex_numbers{
    int real;
    int imag;
};
int main()
{
    
    complex_numbers a,b,c;
    cout << "Enter the real and imaginary parts of the complex no.s respectively" << "\n";
    cin >> a.real >> a.imag;
    cin >> b.real >> b.imag;
    cout << "Adding .... " << "\n";
    c.real =  a.real+b.real;
    c.imag = a.imag+b.imag;
    cout << c.real << " + i" << c.imag << "\n"; 
    return 0;
}
//adding complex
#include<iostream>
using namespace std;
struct complex_numbers{
    int real;
    int imag;
};
int main()
{
    
    complex_numbers a,b;
    cout << "Enter the real and imaginary parts of the complex no.s respectively" << "\n";
    cin >> a.real >> a.imag;
    cin >> b.real >> b.imag;
    cout << "Adding .... " << "\n";
    cout << a.real+b.real << " + i" << a.imag+b.imag << "\n"; 
    return 0;
}
// adding complex 
#include<iostream>
using namespace std;
struct complex_numbers{
    int real;
    int imag;
};
complex_numbers adding_complex(complex_numbers, complex_numbers);
int main()
{
    
    complex_numbers a,b,c;
    cout << "Enter the real and imaginary parts of the complex no.s respectively" << "\n";
    cin >> a.real >> a.imag;
    cin >> b.real >> b.imag;
    cout << "Adding .... " << "\n";
    c = adding_complex(a,b);
    cout << a.real+b.real << " + i" << a.imag+b.imag << "\n"; 
    return 0;
}
complex_numbers adding_complex(complex_numbers a, complex_numbers b){
    complex_numbers outpt;
    outpt.real = a.real >> a.imag;
    outpt.imag = b.real >> b.imag;
    return outpt;
}