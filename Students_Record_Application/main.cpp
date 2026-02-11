#include<iostream>
using namespace std;
#include "Students.h"
namespace App1 { void ProcSt(); } // Function from App1.cpp  cpp by sabita
namespace App2 { void ProcSt(); }  // Function from App2.cpp  cpp by Niloy
Students_Regestered *reg = new Students_Regestered(1000);
int main(){
    Students s1("Ravi", Students::female); reg->add(&s1);
    Students s2("Rhea", Students::male); reg->add(&s2);
    App1::ProcSt(); // App1.cpp by sabita 
    App2::ProcSt(); // App2.cpp by Niloy
    return 0;
}