#include <iostream>
using namespace std;

double power(double baseNum, double powNum) {
    double result = 1;
    for(double i = 0; i < powNum; i++) {
        result = result * baseNum;
    }
    return result;
}
int main()
{
    cout << power(16.10, 20.25);

    return 0;
}