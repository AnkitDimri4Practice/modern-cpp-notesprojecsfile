/* Module Recap 
    - Flexibility of defining customised sort algorithms to be passed as paeameter to sort and search functions defined in the algorithm library
    -  Predefined optimised versions of these sort and search functions can also be used 
    - There are a number of useful functions like rotate, replace, merge, swap, remove etc. in algorithm library 
*/

/* -----Stack and commmon data structure_containers----
    - Understanding implementation and use of stack in C
    - stack in C++ standard library and its use
    - common containers in C++ standard library 
MOdule OUTLINE 
    - 1. Stack in C
        - Common Application of Stack in C
        - Reverse a String 
        - Evaluate a PostFix Expressions
    - 2. Stack in C++
        - Reverse a String 
        - Evaluate a POstfix Expression
    - 3. Data Structures / Containers in C++
        - Containers in C++
    4. Module Summary 

        - Stack is a LIFO(last in first out)containers that can maintain a collection of arbitary number of data items - all of the same type 
        - To create a stack in C we need to:
            - Decide on the data types of the elements
            - Define a structure(container)(with maximum size) for stack and declare a top variable in the structure
            -  Writre seprate functoins for push, pop, top and isempty using the declare structure
    NOte : 
        - 
            - Changed of the data type of elements, implies re-implementation for all the stack codes
            - Change in the structure needs changes in all functions
        - Unlike sin,sqrt, etc function from C standard library, we do not have a ready- made stack that we can use...

    Common  programs using stack 
         some common C programs that use stack: 
            - reversing a string 
                - Input : ABCDE
                - output : EDCBA
            - Evaluation of postfix expression
                - input : 1 2 3 * + 4 - (for 1+2*3-4)
                - output : 3
                Stack Ststes : 
            - idefntification of palindromes(w/and w/o center - marker)
            - Conversion of an infix expression to postfix
            - Depth- first Search (DFS)



}
*/
//  REVERSING A STRING 
#include<stdio.h>
typedef struct stack{
    char data [100];
    int top;
} stack; 
int empty(stack *p){
    return (p->top == -1);
}
int top(stack *p){
    return p-> data [p->top];
}
void push(stack *p,char x){
    p->data [++(p->top)]=x;
}
void pop(stack *p){
    if(!empty(p))(p->top)=(p->top) -1;
}
// Reverse string : EDCBA
int main(){
    stack s;
    s.top = -1;
    char ch, str[10]="ABCDE";
    int i, len= sizeof(str);
    for(i=0;i<len;i++)
        push(&s,str[i]);
    printf("Reversed string : ");
    while(!empty(&s)){
        printf("%c ",top(&s));
        pop(&s);
    }
}
//  Postfix expression evaluation 
#include<stdio.h>
typedef struct stack {
    char data [100];
    int top;
} stack;
int empty(stack *p){
    return (p->top == -1);
} 
int top(stack *p){
    return p->data[p->top];
}
void push(stack *p, char x){
    p-> data[++(p->top)]=x;
}
void pop(stack *p){
    if(!empty(p))(p->top)=(p->top)-1;
}
void main(){ stack s;s.top = -1;
    //  postfix expression : 1 2 3 * + 4 -
    char postfix[]={'1','2','3','*','+','4','-'};
    for(int i = 0;i<7; i++){ char ch= postfix[i];
        if(isdigit(ch)) push(&s,ch-'0');
        else {
            int op2 = top(&s);pop(&s);
            int op1=top(&s);pop(&s);
            switch (ch){
                case '+': push(&s,op1+op2);break;
                case '-':push(&s,op1-op2);break;
                case '*':push(&s,op1*op2);break;
                case '/':push(&s,op1/op2);break;
            }
        }    
    }
    printf("Evaluation %d\n",top(&s)); // incomplete 
}
/* Stack in C++
 - C++ standard library provide ready-made stack for any type of elements 
- Create a stack in C++ we need to :
    - include the stack header
    - Instantiate a stack with proper element type (like char)
    - use the functions of the stack objects for stack operations 
*/

#include<stdio.h>
#include<string.h>
#include "stack.h" // use defined codes
int main(){
    char str[10]="ABCDE";
    stack s; s.top = -1; // stack struct
    for(int i = 0; i<strlen(str);i++)
        push(&s,str[i]);
    printf("Reversed String : ");
    while (!empty(&s)){
        printf("%c ",top(&s)); pop(&s);    
    }
}
/* Lot of code for creating stack in stack.h
top to be initialized 
cluttered interface for stack fucntions 
implemented by user - error -prone
*/
// C++ for stack 
#include<iostream>
#include<cstring>
#include<stack> // library code 
using namespace std;
int main(){
    char str[100]="Ankit Dimri with my interwiew ";
    stack<char>s; // stack class
    for(int i{0};i<strlen(str);i++)
        s.push(str[i]);
    cout << "Reverse string : ";
    while(!s.empty()){
        cout << s.top(); s.pop();
    }
}
/* No code foe creating stack 
MO initialization
clean interface for stack funcitons 
Available in library - well - tested 
*/
#include<iostream>
#include<stack> // Library codes 
using namespace std;
int main(){
    //  Postfix expression : 1 2 3 * + 4 - 
    char postfix[] = {'1','2','3','*','+','4','-'},ch;
    stack<int>s; // stack class 
    for(int i{0};i<7;i++){
        ch=postfix[i];
        if(isdigit(ch)){
            s.push(ch-'0');
        } else {
            int op1 = s.top();s.pop();
            int op2 = s.top();s.pop();
            switch(ch){
                case '*': s.push(op2*op1);break;
                case '-': s.push(op2-op1);break;
                case '/': s.push(op2/op1);break;
                case '+': s.push(op2+op1);break;
            }
        }
    }
    cout << "\nEvaluation : " << s.top();
}
/* Data Structures / Containers  in C++
    - Like stACK, several other data structures are available in C++ standard library 
    - They are ready-made and work like a data type ..
    - VAried types of elements can be used for C++ data structures 
    - Data Structures in C++ are commonly called Containers,
        - A container is a holder object that stores a collection of other objects (its elements)
        - They are implemented as class templates allowing great flexibility in the types supported as elements 
        - The container 
            - Manages the storages space for its elements
            - provides member functions to acess them
            - supports iterators - refrence objects with similar properties to pointers 
        - Many containers have several member duncitons in common, and share functionalities - easy to learn and remember 
        - Stack, queue and priority_queue are implemented as Container Adaptors 
            - Container adaptors are not full container classes, but classes that provide a specific interface relying on an object of one of the container classes(such as deque or list ) to handle the elements 
            - The underlying container is encapsulated in such way that its elements are accessed by the members of the container adaptor independently of the underlying container class used 
*/

