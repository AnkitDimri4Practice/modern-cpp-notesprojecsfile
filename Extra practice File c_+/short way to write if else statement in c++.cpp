#include<iostream>
using namespace std;
int main()
{
    int score, pass;
    cout << "Please enter your score!" << "\n";
    cin >> score;
    pass = (score >= 90) ? 1 : 0;
    cout << " Pass value: " << pass << "\n";
    return 0;  
}