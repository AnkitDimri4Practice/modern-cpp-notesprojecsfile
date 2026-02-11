#include <iostream>
using namespace std;
char monthNames[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char dayNames[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
class Date { enum Month{ Jan = 1, Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec };
    enum Day{ Mon,Tue,Wed,Thr,Fri,Sat,Sun };
    typedef unsigned int UINT;
    UINT date_; Month month_; UINT year_;
    public: 
    Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m),year_(y){ cout << "Date ctor : ";print();cout << "\n"; }
    Date(const Date& d) : date_(d.date_),month_(d.month_),year_(d.year_){ cout << "Date cctor : ";print();cout << "\n"; }
    Date& operator=(const Date& d) { date_ = d.date_;month_ = d.month_;year_ = d.year_;return *this; }
    ~Date(){ cout << "Date dtor : ";print();cout << "\n"; }
    void print()const{ cout <<date_ << "/" << monthNames[month_ - 1] << "/" << year_; }
    bool validDate()const{  // check validity
        return true; } // Not implemented
    Day day() const{ //  Compute day from date using time.h
        return Mon; } // Not Implemented
};
//  Copy constructor and copy Assignment OPerator added
//  Print(), validDate(), and day() made constant member functions
