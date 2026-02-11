#include<iostream>
#include<fstream>
using namespace std;
int main() 
{
    char fileName[40], ch;
    fstream D;
    cout<<"Enter the Name of File = ";
    gets(fileName);
    D.open(fileName, fstream::in);
    if(!D)
    {
        cout << "\n Error Occurred!";
        return 0;
    }
    cout << "\n--Content of = [" << fileName << "] \n";
    while(D>>noskipws>>ch)
        cout << ch;
    D.close();
    cout << "\n";
    return 0;
}