#include <iostream>
using namespace std;
// first name space
namespace first_space{
    void func(){
	    cout << "Inside first_space" << endl;
    }
}
// second name space
namespace second_space{
    void func(){
	    cout << "Inside second_space" << endl;
    }
}
using namespace first_space;
int main (){
    // This calls function from first name space.
    func();
    return 0;
}
Inside first_space
______________________________________________________________________________

#include <iostream>
using namespace std;
// first name space
namespace first_space{
    void func(){
	    cout << "Inside first_space" << endl;
    }
// second name space
    namespace second_space{
        void func(){
            cout << "Inside second_space" << endl;
        }
    }
}
using namespace first_space::second_space;
int main (){
	// This calls function from second name space.
	func();
	return 0;
}
Inside second_space
______________________________________________________________________________

#include <iostream>
using namespace std;
// first name space
namespace first_space{
    void func(){
        cout << "Inside first_space" << endl;
    }
}
// second name space
namespace second_space{
    void func(){
	    cout << "Inside second_space" << endl;
    }
}
int main (){
	// Calls function from first name space.
	first_space :: func();
	// Calls function from second name space.
	second_space :: func();
	return 0;
}
Inside first_space
Inside second_space
______________________________________________________________________________

// Here we can see that more than one variables
// are being used without reporting any error.
// That is because they are declared in the
// different namespaces and scopes.
#include <iostream>
using namespace std;

// Variable created inside namespace
namespace first {
	int val = 500;
}

// Global variable
int val = 100;
int main(){
	// Local variable
	int val = 200;
	// These variables can be accessed from
	// outside the namespace using the scope
	// operator ::
	cout << first::val << '\n';
	return 0;
}
500
______________________________________________________________________________

#include <iostream>
using std::cout;
int main (){
	cout << "std::endl is used with std!" << std::endl;
	return 0;
}
std::endl is used with std!
______________________________________________________________________________

// Creating namespaces
#include <iostream>
using namespace std;
namespace ns1 {
	int value() { return 5; }
} // namespace ns1
namespace ns2 {
	const double x = 100;
	double value() { return 2 * x; }
} // namespace ns2
int main(){
	// Access value function within ns1
	cout << ns1::value() << '\n';
	// Access value function within ns2
	cout << ns2::value() << '\n';
	// Access variable x directly
	cout << ns2::x << '\n';
	return 0;
}
5
200
100
______________________________________________________________________________

// A C++ program to demonstrate use of class
// in a namespace
#include<iostream>
using namespace std;

namespace ns{
	// A Class in a namespace
	class geek{
	public:
		void display(){
			cout<<"ns::geek::display()"<<endl;;
		}
	};
}
int main(){
	// Creating Object of geek Class
	ns::geek obj;
	obj.display();
	return 0;
}

______________________________________________________________________________

// A C++ program to demonstrate use of class
// in a namespace
#include <iostream>
using namespace std;
namespace ns {
// Only declaring class here
	class geek;
} // namespace ns
// Defining class outside
class ns::geek {
	public:
		void display() { cout << "ns::geek::display()\n";
	}
};
int main(){
	// Creating Object of geek Class
	ns::geek obj;
	obj.display();
	return 0;
}

______________________________________________________________________________
// A C++ code to demonstrate that we can define
// methods outside namespace.
#include <iostream>
using namespace std;
// Creating a namespace
namespace ns {
	void display();
	class geek {
		public:
		void display();
	};
} // namespace ns
// Defining methods of namespace
void ns::geek::display(){
	cout << "ns::geek::display()\n";
}
void ns::display() { cout << "ns::display()\n"; }
// Driver code
int main(){
	ns::geek obj;
	ns::display();
	obj.display();
	return 0;
}
