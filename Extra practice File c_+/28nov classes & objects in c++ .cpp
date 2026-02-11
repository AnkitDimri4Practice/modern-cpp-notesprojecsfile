#include <iostream>
using namespace std;
class Book {
public:
    string title;
    string author;
    int pages;
};
int main() {
    Book Book1;
    Book1.title = "do and die";
    Book1.author = "ANkit";
    Book1.pages = 500;
    //cout << Book1.pages;

    Book Book2;
    Book2.title = "NO";
    Book2.author = "ANkit dIMRI";
    Book2.pages = 700;
    Book2.title = "Hunger games";
    cout << Book2.title << endl;
    cout << Book2.author << endl;
    cout << Book2.pages << endl;



    return 0;
}