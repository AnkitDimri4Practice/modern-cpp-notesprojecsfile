//fibonacci
#include<iostream>
using namespace std;
int main()
{
    int n1=0,n2=1,n3,i,n;
    cout << "Enter the number of the elements: ";
    cin >> n;
    cout << n1 << n2 << " ";
    for(i=2; i<n; i++){
        n3 = n1+n2;
        cout << n3 << " ";
        n1=n2;
        n2=n3;
    }
    return 0;
}
// palindrome
#include<iostream>
using namespace std;
int main()
{
    int n,r,sum=0,T;
    cout << "Enter the numbers = ";
    cin >> n;
    T= n;
    while (n>0)
    {
        r=n%10;
        sum = (sum *10)+r;
        n=n/10;
    }
    if(T==sum){
        cout << " No is palindrome!" << "\n";
    } else {
        cout << " No is not palindrome.." << "\n";
    }
    return 0;
}
// prime
#include<iostream>
#include<cstring>
using namespace std;
void SieveOfTosthenes(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p = 2; p*p<=n; p++){
        if(prime[p]==true){
            for(int i = p*p; i<=n; i+=p)
            prime[i]=false;
        }
    }
    for(int p = 2; p<=n; p++)
        if(prime[p])
            cout << p << " ";
}
int main()
{
    int n;
    cout <<  "please enter the limit of the prime number series = ";
    cin >> n;
    cout << "following are the prime numbers series smaller and equal to  " << n << "\n";
    SieveOfTosthenes(n);
    return 0;
}
// factorial
#include<iostream>
using namespace std;
int fact(int n){
    if((n==0) ||(n==1))
    return 1;
    else 
    return n*fact(n-1);
}
int main()
{
    int n;
    cout << " Enter any no = ";
    cin >> n;
    cout << " FActorial of " << n << " is : " << fact(n);
    return 0;
}
//Swap without using 3rd variable
#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cout << " please enter the value of a and b = ";
    cin >> a >> b;
    cout <<" A = " << a  << "\t B = " << b << "\n";
    a=a+b;
    b=a-b;
    a=a-b;
    cout << " After swap of a = " << a << " and b is = " << b;
    return 0;
}
// full pyrymid
#include<iostream>
using namespace std;
int main()
{
    int r;
    cout << " please enter the row = ";
    cin >> r;
    for(int i = 1; i<=r; i++){
        for(int k =r-i; k>0; k--){
            cout << " ";
        }
        for(int j = 1; j<=(2*i-1); j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
//half
#include<iostream>
using namespace std;
int main()
{
    int r;
    cout << " please enter the row = ";
    cin >> r;
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
//sum of digit program in c++
#include<iostream>
using namespace std;
int main()
{
    int n, sum = 0, m;
    cout << " enter a n = ";
    cin >> n;
    while(n>0){
        m=n%10;
        sum=sum+m;
        n=n/10;
    }
    cout << "Sum is = " << sum << "\n";
    return 0;
}
 enter a n = 
23444545
Sum is = 31

