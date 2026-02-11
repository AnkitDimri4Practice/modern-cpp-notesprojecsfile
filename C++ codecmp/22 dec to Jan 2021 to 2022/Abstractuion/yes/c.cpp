#include <iostream>
#include <string>
#include <vector> // For std::vector
#include <fstream> // For std::ifstream and std::ofstream
using namespace std;
int main() {
    // Store the contents into a vector of strings
    vector<string> outputs;

    // Create the file object (input)
    ifstream infile("c.txt");

    // Temporary buffer
    string temp;

    // Get the input from the input file until EOF
    while (getline(infile, temp, ' ')) {
        // Add to the list of output strings
        outputs.push_back(temp);
    }

    // Use a range-based for loop to iterate through the output vector
    for (const auto& i : outputs)
        cout << i << endl;

    return 0;
}