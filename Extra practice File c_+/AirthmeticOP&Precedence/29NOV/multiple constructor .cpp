#include <iostream>
using namespace std;
class Book {
    public:
        string title;
        string author;
        int pages;

        Book()
        {
            title = "no title";
            author = "no author";
            pages = 0;
        }
        Book(string aTitle, string aAuthor, int aPages) { //a-- argument
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
};

int main()
{
    Book book1("The tale of two birds", "Ankit", 900);
    Book book2("THE hidden stone", "Ankit Dimri", 700);
    /*cout << book2.title << endl;
    cout << book1.pages << endl;*/
    Book book3("piddu", "Jyoti khanduri", 300);
    cout << book3.title << endl;
    return 0;
}
