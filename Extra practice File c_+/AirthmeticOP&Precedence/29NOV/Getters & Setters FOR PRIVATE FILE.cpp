#include<iostream>
using namespace std;
class Movie {
    private:
        string rating;
    public:
        string title;
        string director;
        Movie(string aTitle, string aDirector, string aRating) {
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }
        void setRating(string aRating) {
            if(aRating == "G" || aRating == "R" || aRating == "NR" || aRating == "PG-13" || aRating == "PG") {
                rating = aRating;
            } else {
                rating = "NR";
            }
        }
        string getRating() {
            return rating;
        }
};
int main()
{
    Movie avengers("The Avengers", "Joss whedon", "PG-13");
    avengers.setRating("PG-15");
    cout << avengers.getRating();
    return 0;
}