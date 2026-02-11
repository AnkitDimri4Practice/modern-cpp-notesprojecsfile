// Counting the no of vowels and consonants in a String..
#include <iostream>
using namespace std;
int main() {
   char str[50];
   int vowels, consonants;
   vowels = consonants = 0;
   cout << "Enter any String " << "\n";
   gets(str);
   for(int i = 0; str[i]!='\0'; ++i) {
      if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' || str[i]=='u' 
      || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' ||str[i]=='U') {
        vowels++;
      } else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
        consonants++;
      }  
   }
   cout << "The string is: " << str << "\n";
   cout << "The vowels in this String: " << vowels << "\n";
   cout << "The consonants in this String: " << consonants << "\n";
   return 0;
}