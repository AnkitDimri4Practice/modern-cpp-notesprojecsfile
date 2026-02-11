#include<iostream>
using namespace std;
int main()
{
    int score, pass;
    cout << " Please enter the score! " << endl;
    cin >> score;
    if (score >= 50) 
    {
        if (score >= 80)
            {
                cout << "congrats!" <<endl;
            }
        else
            {
                cout << "You tried your best!" << endl;
            }
    } else{
        if (score >= 40)
            {
                cout << "Well at least you passed" << endl;
            } 
        else 
            {
                cout << "Better luck next time!" << endl;
            }
    }
    
    return 0;
}