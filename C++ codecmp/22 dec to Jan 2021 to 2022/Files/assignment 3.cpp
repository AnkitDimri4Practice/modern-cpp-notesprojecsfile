// write a program to print all the duplicates in the input string. *
// #include<iostream>
// using namespace std;
// # define NO_OF_CHARS 256
// class duplicate_char{
//    public :
//    void charCounter(char *str, int *count){
//       int i;
//       for (i = 0; *(str + i); i++)
//       count[*(str + i)]++;
//    }
//    void DisplayDuplicateCharacters(char *str){
//       int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
//       charCounter(str, count);
//       for (int i = 0; i < NO_OF_CHARS; i++)
//          if(count[i] > 1)
//             printf("%c\t\t\t%d \n", i, count[i]);
//       free(count);
//    }
// };
// int main(){
//    duplicate_char DupChar ;
//    char str[] = "I want to be a good Programmer.....";
//    cout<<"The duplicate characters in this string"<<"\n";
//    cout<<"\ncharacter\tcount\n";
//    DupChar.DisplayDuplicateCharacters(str);
//    return 0;
// }





// write a program to check whether a given character is contained in a string or not and find its position?

// #include<iostream> 
// using namespace std; 
// int searchChar(string &s, char c) { 
// 	int index = -1; 
// 	for (int i = 0, n = s.size(); i<n; i++) { 
// 		if (s[i] == c) { 
// 			index = i; 
// 			break; 
// 		} 
// 	} 
// 	return index; 
// }  
// int main() { 
// 	cout << "Enter a string = "; 
// 	string s; 
// 	cin >> s; 
// 	cout << "Enter a character to search in '" << s << "' : "; 
// 	char c; 
// 	cin >> c; 
// 	int index = searchChar(s, c); 
// 	if (index != -1) { 
// 		cout << "Found character at index: " << index  << endl; 
// 	} else { 
// 		cout << "Character is not present in the string!" << endl; 
// 	} 
// 	return 0; 
// }



// Counting the no of vowels and consonants in a String..
// #include <iostream>
// using namespace std;
// int main() {
//    char str[50];
//    int vowels, consonants;
//    vowels = consonants = 0;
//     cout << "Enter any String " << "\n";
//    gets(str);
//    for(int i = 0; str[i]!='\0'; ++i) {
//       if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' || str[i]=='u' 
//       || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' ||str[i]=='U') {
//         vowels++;
//       } else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
//         consonants++;
//       }  
//    }
//    cout << "The string is: " << str << "\n";
//    cout << "The vowels in this String: " << vowels << "\n";
//    cout << "The consonants in this String: " << consonants << "\n";
//    return 0;
// }



// #include<iostream>
// using namespace std;
// int main(){
//     char str[100];
//     int vowels,consonants;
//     vowels = consonants = 0;
//     cout << "enter the string " << "\n";
//     gets(str);
//     for(int i = 0;str[i] != '\0';i++){
//         if(str[i]=='a' || str[i] == 'e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i] == 'A' || str[i]=='E' || str[i] == 'I' || str[i]=='O' || str[i]=='U'){
//             vowels++;
//         } else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
//             consonants++;
//         }
//     }
//     cout << "The string is : " << str << "\n";
//     cout << "The vowels in this string : " << vowels << "\n";
//     cout << "The consonants in this string " << consonants << "\n";
//     return 0;
// }


