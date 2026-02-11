#include <iostream>
using namespace std;
int main()
{
    int numberGrid[4][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12}
                        } ;
    /*cout << numberGrid[3][1];*/
    for(int i = 2; i < 4; i++) {
        for(int j = 2; j < 3; j++) {
            cout << numberGrid[i][j];
        }
        cout << endl;
    }

    return 0;
}