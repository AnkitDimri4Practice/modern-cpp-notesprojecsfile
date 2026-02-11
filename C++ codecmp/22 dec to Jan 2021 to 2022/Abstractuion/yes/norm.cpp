// //  Writing to Output File 
// #include<iostream>
// #include<fstream>
// using namespace std;
// int main(){
//     ofstream my_file;  // Output stream
//     my_file.open("c.txt");
//     my_file << "Writing this to a file.\n";
//     my_file.close();
// }


//  Reading from Input File 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){ 
    ifstream my_file("example.txt");
    int x;
   stringstream ss( myString );
   ss >> x;
   return x;
    string line;
    if (my_file.is_open()){
        while(!my_file.eof())
            my_file >> line;
            cout << line << "\n";
        my_file.close();
    }
    else cout << "\nUnable to open the file";
}

// getline(my_file, line)   