#include<iostream>
using namespace std;
#include "Stack.h"
int main(){
    Stack s; char str[10] = "ABCDE"; 
    for(int i = 0; i<5; ++i) s.push(str[i]);
    while (!s.empty()){
        cout << s.top(); s.pop();
    }
}