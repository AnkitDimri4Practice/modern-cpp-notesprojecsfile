#include<iostream>
#include<conio.h>
using namespace std;
int main() {
    int a[3] = {10,-5};
    for(int i=0; i<2; i++) {
        int x = a[i];
        try {
            if (x > 0)
                throw x;
            else
                throw 'x';
        } catch (int x) {
            cout << " Integer exception & that integer is = " << x;
        } catch (char x) {
            cout << "\n Character exception & that character is = " << x;
        }
    }
}
