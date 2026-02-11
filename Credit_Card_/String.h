#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class String { 
    char *str_; size_t len_; 
    public: 
    String(const char *s) : str_(strdup(s)),len_(strlen(str_)) {
        cout << "String ctor : "; print(); cout << "\n";
    }
    String(const String& s) : str_(strdup(s.str_)),len_(strlen(str_)){
        cout << "String cctor : "; print();cout << "\n";
    }
    String& operator=(const String& s){
        if(this != &s) {
            free(str_);
            str_ = strdup(s.str_);
            len_ = s.len_;
        }
        return *this;
    }
    ~String(){
        cout << "String Dtor : "; print();cout << "\n";free(str_);
    }
    void print()const{
        cout << str_;
    }
};
// Copy Constructor and Copy Assignment operator added 
//   print() made a cosntant member function 
