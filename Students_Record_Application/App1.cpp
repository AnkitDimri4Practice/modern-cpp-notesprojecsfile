//  processing for females by Niloy
#include<iostream>
using namespace std;
#include "Students.h"
extern Students_Regestered *reg;
namespace App1{
    void ProcSt(){ // void case not work 
        cout << "MALE STUDENTS: \n";
        int r = 1; Students *s;
        while (s = reg->getStudent(r++))
        if(s->getGender() == Students::male)
            cout << *s;
        cout << "\n\n";
        return;
    }
};