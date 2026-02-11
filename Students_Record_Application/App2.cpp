//  processing for males by sabita 
#include<iostream>
using namespace std;
#include "Students.h"
extern Students_Regestered *reg;
namespace App2 {
    void ProcSt(){
        cout << "FEMALE STUDENTS: \n";
        int r = 1; Students *s;
        while (s = reg->getStudent(r++))
        if(s->getGender() == Students::female) 
            cout << *s;
        cout << "\n\n";
        return;
    }
};