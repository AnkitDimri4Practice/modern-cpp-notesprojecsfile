#include<iostream>
using namespace std;
int main()
{
    int score;
    cout << "enter ur score : " << endl;
    cin >> score;
    if (score >= 60) {
        if (score >= 80) {
            cout << "congrats!" << endl;
        } else {
            cout << "u tried ur best! " << endl;
        }
    } else {
        if (score >= 40) {
            cout << "well atleast u passed : " << endl;
        } else {
            cout << " better luck next time: " << endl;
        }
    }
    return 0;

}