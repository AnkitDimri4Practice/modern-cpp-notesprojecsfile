
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int isum = 0;
    int iConstantRatio,iNumTerms,iFirstTerm;
    cout << "plese enter the constant Ratio :" << "\n";
    cin >> iConstantRatio;
    cout << "please enter the numbers of terms " << "\n";
    cin >> iNumTerms;
    for(int i = 1; i<=iNumTerms;i++){
        iFirstTerm = 1;
        for(int j = 1; j<i;j++){
            iFirstTerm *= iConstantRatio;
            cout << iFirstTerm << " ";
        }
        isum += iFirstTerm;
        cout << "[" << isum << "]" << "\n";
    }
    cout << "\n" << "Sum = " << isum << "\n";
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    string ipt_string;
    cout << "Enter any string ";
    cin >> ipt_string;
    int len = ipt_string.length();
    char rev_string[len];
    for(int i = 0;i<len;i++){
        rev_string[i]=ipt_string[len-1-i];
    }
    bool is_palindrome= true;
    for(int i = 0;i<len;i++){
        if(rev_string[i]==ipt_string[i]){
            continue;
        } else {
            is_palindrome=false;
            break;
        }
    }
    if(is_palindrome){
        cout << "The input string " << ipt_string << " is a palindrome :: " << rev_string << "\n";
    } else {
        cout << "The input string " << ipt_string << " is not a palindrome " << rev_string << "\n";
    }
    return 0;
}

#include<iostream>
#include<string>
using namespace std;
#define NO_OF_CHARS 256
class dulpicate_char{
    public:
    void charccounter(char *str, int *count){
        for(int i = 0; *(str+i);i++)
        count[*(str+i)]++;
    } 
    void printduplicatecharacter(char *str){
        int *count = (int *)calloc(NO_OF_CHARS,sizeof(int));
        charccounter(str,count);
        for(int i = 0; i<NO_OF_CHARS; i++)
            if(count[i]>1)
                printf("%c\t\t\t%d \n",i,count[i]);
        free(count);
    }
};
int main()
{
    dulpicate_char dupchar;
    char str[] = " nahi mene nahi socha is baare me908984....";
    cout << "The duplicate character in this string " << "\n";
    cout << "Character\tcount\n";
    dupchar.printduplicatecharacter(str);
    return 0;
}