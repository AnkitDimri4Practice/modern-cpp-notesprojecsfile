//  Conditional programming 06-05-22
// If clause-else -expression nested  statement - doing things conditionally
#include<iostream>
int main()
{
    int number1{55};
    int number2{66};
    bool result{(number1<number2)};
    std::cout << "--------------------------------" << "\n";
    std::cout << std::boolalpha << "result : " << result << "\n\n";
    std::cout << "Free standing if statement " << "\n";
    // if(result)
    if(result==true){
        std::cout << number1 << " is less than " << number2  << std::endl;
    } // if(!result)
    if(!(result==true)){
        std::cout << number1 << " is not less than " << number2 << "\n";
    }

    // using else 
    std::cout << "\n" <<"using the else clause : " << "\n";
    if(result==true){
        std::cout << number1 << " is less than " << number2 << "\n";
    } else {
        std::cout << number1 <<  "is NOT less than " << number2 << "\n";
    }

    // using expression as condition directly 
    std::cout << "\n" << "Using expression as condition : " << "\n";
    if(number1<number2){
        std::cout << number1 << " is less than " << number2 << "\n";
    } else {
        std::cout << number1 << " is NOT less than " << number2 << "\n";
    }

    std::cout << "--------------------------------" << "\n";
    bool red{false};
    bool green{true};
    bool yellow{true};
    bool police_stop{false};
    /*
        if green : go
        if red,yello : stop
        if green and police_stop : stop
    */
    if (red,police_stop){
        std::cout << "STOP"<< "\n";
    }if (yellow){
        std::cout << "Slow down"<< "\n";
    }if (green){
        std::cout << "Go" << std::endl;
    }// Nested conditions
    std::cout << "\n" << "Police officer stops(verbose)" <<"\n";
    if(green){
        if(police_stop){
            std::cout << "STop" << "\n";
        } else {
            std::cout << "Go" << "\n";
        }
    }// Nesting Alternative 
    std::cout << "\n" << "Police officer stops(less verbose)" << "\n";
    if(green && !police_stop){
        std::cout << "GO" << "\n";
    } else {
        std::cout << "STOP" << "\n";
    }
    std::cout << "--------------------------------" << "\n\n";
    return 0;
}

// else if clause 07-05 
// Tools  :: -> Testing for severral different conditions
// Tools  :: -> Testing for severral different conditions
#include<iostream>
#include<string>
const int Pen{19};
const int Marker{20};
const int Eraser{30};
const int Rectangle{40};
const int Circle{50};
const int Ellipse{60}; 
const int a{35};
const int b{20};
int main()
{
    std::cout << " -------------------------------" << "\n";
    int tool{Eraser};
    if(tool==Pen){
        std::cout << "Active tool is pen : " << "\n";
        // Do the actual painting 
    }
    else if(tool==Marker){
        std::cout << "Active tool is Marker : " << "\n";
    }
    else if(tool==Eraser){
        std::cout << "Active tool is Eraser : " << "\n";
    }
    else if(tool==Rectangle){
        std::cout << " Active tool is rectangle : " << "\n";
    }
    else if(tool==Circle){
        std::cout << " Active tool is Circle : " << "\n";
    } 
    else if(tool==Ellipse){
        std::cout << "Active tool is Ellipse : " << "\n";
    }
    std::cout << "Moving on Next switch statement " << std::endl;
    std::cout << "------------------------" << "\n";
    //  Switch clause
    /* Break : - The break statement after each case is very important. It stops processing
 the switch block when a successful case has been found. If the break statemment is not
  there, all the cases following the current case will be executed.

    Conditions : integral types and enums : int, long, unsigned short,etc... */
    
    switch(tool){
        case Pen: {
        std::cout << "Active tool is pen : " << "\n";
        // Do the actual painting 
        }
        break; 
        case Marker: {
        std::cout << "Active tool is Marker : " << "\n";
        }
        break;
        case Eraser : 
        case Ellipse : {
            std::cout << "Drawing shape : " << "\n";
        }
        break;
        case Circle : {
            std::cout << "Active tool is Circle : " << "\n";
        }
        break; 
        default: {
            std::cout << "can't match any tool" << "\n";
        } 
    }
    std::cout << "Moving On" << "\n" << " -------------------------------" << "\n";
    int max{};
    std::cout << "\n" << "using regular if " << std::endl;
    max = ((a>b) && (a<b)) ? a:b; 
    std::cout << "Max : " << max << std::endl;
    std::cout << "Moving On" << "\n" << " -------------------------------" << "\n";
    //  Ternary Initialization 
    std::cout << "\n" << "Speed" << "\n";
    bool fast = false;
    int speed {fast ? 300 : 150};
    std::cout << "The speed is : " << speed << "\n";
    std::cout << "Moving On" << "\n" << " -------------------------------" << "\n";
    bool max_1 = false;
    int gret {max_1 ? 24 : 45};
    std::cout << "The maximum numbers : " << gret << "\n";
    std::cout << "Moving On" << "\n" << " -------------------------------" << "\n";
    return 0;
} 