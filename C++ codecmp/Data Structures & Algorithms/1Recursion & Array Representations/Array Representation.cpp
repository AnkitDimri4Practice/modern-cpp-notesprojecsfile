    >  1. Introducntion , Declaration, Demo
        2. Static array vs dynamic array, CODE
        3. Increase array size, CODE
        4. 2D array 
        5. 2D array Demo
        6. Array representation by compiler
        7. Row major formula for 2d arrays
        8. Column major formula for 2d arrays 
        9. Formulas for nD arrays
        10. Formulas for 3D arrays 

    > - What are variables 
        Single valued variables - Scalar variables. 
        Eg: int x = 10;
            x-10[1000/1001]-2bytes  M.M - main memory 

>    What is abn arrqy?
        - Collection of same type of elements.
        - Used to store a list of values in a single variable.
        - Vector variable.
        - Eg: A[5];
        - Total 10 bytes of memory will be allocated at declaration.
        - Elements will be stored in containous memory locations. 
        - Elements are accessed using indices.

            1. Array Declaration 
                - Method -1 (Declaration only)
                    int A[5];
                - Method -2 (Declaration+Initialisation)
                    int A[5]={1,2,3,4,5};
                - Method-3 (Declaration+Semi-Initialisation(rest 0))
                    int A[5]={1,2,3};
                    int A[5]={0};
                - Method-2 (Auto-size)
                    int A[]={2,3,4,5,6};
                --
            --Accesssing array elements
                - int A[5]-{1,2,3,4,5};
                - printing one element:
                cout << A[3] << " \n";
                - printing whole array:

        --    
    --    

        #include<iostream>
        using namespace std;
        int main()
        {
            int A[10];
            cout << "A : [";
            for(int i{0};i<10;i++){
                cout << A[i] << " "; // All are garbage value.
            }
            int B[5]{10,20,30,40,50};
            cout << "]\nB : [";
            for(int i{0};i<5;i++){
                cout << B[i] << " ";
            }
            float C[7]{1.2,3.4,4.5,56.5};
            cout << "]\nC : [";
            for(int i{0};i<7;i++){
                cout << C[i] << " ";
            }
            int D[]{100,200,90};
            cout << "]\nD : [";
            for(int i{0};i<3;i++){
                cout <<D[i] << " ";
            }
            cout << "]\n";
            return 0; 
        }

> 2.- Static array 
        -  Size of array is static (Decided at compile time)
        - int A[5];
            int n;
            cin>>n;
            int B[n];
        Created in stack
    - Dyanmic array :
        created in heap using pointers.- create in the stack memory 
            int *o;
                p=new int[5];
        Deleting the memory -heap memory cann't be access by the code,code cann't access the heap memory...
            delete []p;
            p=null;


#include<iostream>
using namespace std;
int main(){
    int a[5]{1,2,3,4,5}; // Static array
    cout <<a[3] << "\n";
    //  Dynamic Array 
    int *p;
    p=new int[5];
    p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5;
    cout << p[2] << "\n";
    return 0;
}


> 3. Icrease array size --\  // 1-07-22
    Create another big size array and copy elements into it..
        int *p = new int[5];
        int *q = new int[10];
        for(int i =0; i<5; i++){
            q[i]=p[i];
        }
        delete []p;
        p=q;
        q=NULL;

#include<iostream>
using namespace std;
int main(){
    int *p;
    p=new int[5];
    for(int i{0};i<5;i++){
        p[i]=10;
    }
    int *q;
    q=new int[6];
    for(int i{0};i<6;i++){
        q[i]=p[i];
    }
    q[5]=20;

    cout << "P : ";
    for(int i{0};i<5;i++){
        cout << p[i] << " ";
    }
    cout << "\n";

    cout << "Q : ";
    for(int i{0};i<6;i++){
        cout << q[i] << " ";
    }
    cout << "\n";
    return 0;
}         

>  2D Arrays - 
        - [ Accessed using 2 Indices.
        - Used for implementing matrics and tables.] In memory, It will stored Linearly 
    - Create  a 2D array :-
         Method 1:                          Method  2:                     Method 3
        - int A[3][4];                      int *A[2];                     int **A; - Double pointer 
        - int A[2][2] = {{1,2},{3,4}}       A[0]=new int[4];               A=new int*[2];
        Declaration                         A[1]=new int[4];               A[0]=new int[2];
                                                                           A[1]=new int[2];
            
    Accessing elements of a 2D array 
            Nested for loop
        int A[3][2];
        for(int i{0}; i<3; i++){
            for(int j{0};)j<2;j++){
                A[i][j]=1;
            }       
        }

#include<iostream>
using namespace std;
int main()
{
    //  Method 1:
    int A[3][4]; // Array Declaration 
    int B[2][3]{{1,2,3},{3,4,5}};
    // Method 2: 
    int *C[2];
    C[0]=new int[3];
    C[1]=new int[3];
    //  Method 3:
    int **D;
    D=new int*[2];
    D[0]=new int[3];
    D[1]=new int[3];
    return 0;
}

> Array representation by compiler
    How compile manages scalar variables
        int x{10};cout << x;
    Formula for calculating array address
Address([n])=Base address + (required index - starting index(0))*size of data type
address(A[1]) = 100   +       (1            -       0)              *   2 
                = 100 + 2
                = 102
04-07-22

> Row major formula for 2D arrays -   
            How 2D arrays are handles by complier ?
                - int A[3][4];
                - Visuaalised in form of a matrix.
                - But actual memroy allocation will be linear. 
                - There are two methods of mappping a matix into a 1D - row major order and column major order.
        - Row major mapping 
            - int A[3][4];
            Elements are stored row by row.
            Formula for accessing 2D arrays. [1|2|3|4|5|6|7|8|9|10|11|12]
                                              ______   ______  _______
            address(A[1][2]) = b.a + [4 + 2] * D.T size 
                            = 100 + (6*2)
                            = 100 + 12
                            = 112 
            A[m][n]
        > [    add(A[i][j]) = b.a + [i*n + j] * w - size of data type ]

 05-07-2022

> Column major formula for 2D array
    - int A[3][4];
    - Elements are stored columns by column.
    - Formula for accessing 2D array:
         [ add(A[1][2]) = BA + (2*3 + 1)* 2 ]
                = 100 +(6+1)*2
                = 114
    [ add(A[i][j]) = BA + (j*m + i)* w ]
    
>  Formulas for nD arrays 

        - Row major mapping 
            - A[d1][d2][d3][d4];
            - Add(A[i1][i2][i3][i4]) = BA+(i1*d2*d3*d4 + i2 *d3*d4 + i3 *d4 *i4) ....  w = size of datatypes

    - General formula = address(A[i1][i2][i3][i4]........[in])= BA + [summation of p=1 to n i^p * product of q= p+1 to n d base q] * w
- Columns major mapping 
        - A[d1][d2][d3][d4]; Add(A[i1][i2][i3][i4])
            - address(A[i1][i2][i3][i4]........[in])= BA + [summation of p=n to 1 i^p * product of q= 1 to p-1 d base q] * w


>  Formulas for the 3D Array
    - Row major mapping 
        - A[l][m][n];
        - Add([i][j][k])
        add(A[i][j][k])=BA+[i*m*n + j*n + k]*w'
    - Column major mapping 
        - add(A[i][j][k]) = BA + [k*l*m + j*l + i] * w

    _____________________________________Complete_________________________________________




