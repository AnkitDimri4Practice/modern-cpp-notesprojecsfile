#include<iostream>
using namespace std;
class Shape {
    public:
        virtual float Area() = 0;
    void Width(float w){
        width = w;
    }
    void Height(float h) {
        height = h;
    }
    protected:
        float width;
        float height;
};
class Rectangle: public Shape {
    public:
        float Area() { 
            cout << "please enter the value of width and height" << "\n";
            cin >> height >> width;
            cout << " Area of Rectangle = [" << (width * height) << "] \n\n";
        return (width * height); 
    }
};
class Triangle: public Shape {
    public:
        float Area() { 
            cout << "please enter the value of width and height" << "\n";
            cin >> height >> width; 
            cout << " Area of Triangle = [" << (width * height)/2 << "]";
        return (width * height)/2; 
    }
};
int main(void){
    Rectangle R;
    Triangle T;
    R.Area();
    T.Area();
    return 0;
}