// #include <iostream>
// #include <string>
// int main (){
//   std::string str="We think in generalities, but we live in details.";
//   std::string str2 = str.substr (3,6); 
//   std::size_t pos = str.find("live"); 
//   std::string str3 = str.substr (pos); 
//   std::cout << str2 << ' ' << str3 << '\n';
//   return 0;
// }


#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
   int i,j,Val;
   string s1;
   const string *p = &s1; 
   string s2;
   const string *P = &s2;
   cout << "Enter the String = ";
   getline(cin,s1);
   cout << " Enter the Substring = ";
   getline(cin,s2);
   for(i = 0; i < s1.size();i++) {
      j=0;
      if(s1[i]==s2[j]) {
         Val=i+1;
         while(s1[i]!='\0' && s2[j]!='\0' && s1[i]==s2[j]) {
            i++;
            j++;
         } if(s2[j]=='\0') {
               cout<<"The substring is exists in given string at position = " << Val << "\n";
               exit(0);
            } else {
               i=Val;
               Val=0;
            }
        }
    } if(Val==0)
        cout<<"The substring is not exists in given string\n";
    return 0;
}