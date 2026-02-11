#include<iostream>
using namespace std;
int main()
{
    int score;
    char grade;
    cout << " Enter score (0-100): ";
    cin >> score;
    if(score<0 || score>100)
    {
        cout << " Invalid score. " << endl;
        return 0;
    }
    switch (score/10)
    {
    case 10:
    case 9:
        grade = 'A++';
        break;
    case 8:
        grade = 'A+';
        break;
    case 7:
        grade = 'A';
        break;
    case 6:
        grade = 'B';
        break;
    case 5:
        grade = 'C';
        break;
    case 4:
        grade = 'D';
        break;
    case 3:
        grade = 'E';
        break;
    case 2:
        grade = 'F';
        break;
    default:
        grade = 'G';
        break;
    }
    cout << "Grade = " << grade << endl;
    return 0;
}