#include<iostream>
using namespace std;
namespace open{         // First definition 
    int x = 30; 
}
namespace open {       // Additions to the last definition 
    int y = 40;
}
int main(){
    using namespace open;   // Both x and y would be available 
    x = y = 20;
    cout << "Output : " << x << " " << y << "\n";
} 
Output : 20 20