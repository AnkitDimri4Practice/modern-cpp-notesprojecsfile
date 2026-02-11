#include <iostream>
using namespace std;
int main()
{
    int score;
    cout << "Please enter you score!" << endl;
    cin >> score;
    if (score > 90)
        {
            cout << "Congrats! You get faster wifi and new smartphone!" << endl;
        }
            else if (score > 80)
            {
                cout << "You studied very hard. better luck next time. congrats on better wifi!"
            } 
            else if (score < 60) 
            {
                cout << "You are not getting either of new wifi or smartphone. Start studying!"
            }
    else 
        {
        cout << "You can do way better. let me know if i can help you anyhow!" << endl;
        }
        
        cout << "Code is working evan after the conditionals!" << endl;
    return 0;
}