#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<numeric>
using namespace std;
void D(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p = 2; p*p<=n; p++){
        if(prime[p]==true){
            for(int i =p*p; i<=n;i+=p)
            prime[i]=false;
        }
    }
    for(int p =2; p<=n; p++)
        if(prime[p])
            cout << p << " ";
};
int arraySum(vector<int> &v){
    int initial_sum{0};
    return accumulate(v.begin(),v.end(),initial_sum);
}
void pascaltri(int n){
    for(int i = 1; i<=n; i++){
        int coef=1;
        for(int k = n-i;k>0;k--){
            cout << " ";
        }
        for(int j = 1; j<=i;j++){
            cout << coef << " ";
            coef=coef*(i-j)/j;
        }
        cout << "\n";
    }
}
int main()
{
    int isum,iFirstTerm, iNumTerms, iConstantRatio;
    cout << "Please enter the constant ratio : ";
    cin >> iConstantRatio;
    cout << "Please enter the Number of terms : ";
    cin >> iNumTerms;
    cout << "please enter the first term : ";
    cin >> iFirstTerm;
    for(int i = 1; i<=iNumTerms; i++){
        iFirstTerm = 1;
        for(int j = 1; j<i; j++){
            iFirstTerm*=iConstantRatio;
            cout << iFirstTerm << " ";
        }
        isum +=iFirstTerm;
        cout << "[" << isum << "]\n";
    }
    cout << "\nSum : " << isum << "\n";
    int  P{123};
    cout << "Follwing are the prime number smaller and equal to : " << P << "\n";
    D(P);
    cout << "-----------------------"<< "\n";
    float a{3},b{2},d,c{20},n,Sum;
    d=a;
    z:
    if(a<=c){
        cout << a <<  " ";
        a=a+b; 
        goto z;
    } else if(d>c){
        cout << "It's not valid..." << "\n";
    }
    c=a+(n-1)*b;
    cout << "\nNUmber of terms : " << n << "\n";
    Sum = n*0.5*(2*a+((n-1)*d));
    cout << "Sum : " << Sum << "\n";
    cout << "---------------" << "\n";
    int n1{12},val{1},x{5};
    for(int i = 0; i<n1;i++){
        val *= x;
        cout << "P : " << i << val << " ";
    }
    cout << "\nPower of : " << x << " to the power " << n1 << " is " << val << "\n";
    cout << " -------------------------- " << "\n";
    int n2;
    float average,sum{0},val1;
    cout << "how many numbers you want to enter : ";
    cin >> n2;
    for(int z = 1; z<=n2; z++){
        cout << "\nEnter the number  " << z << " ";
        cin >> val1;
        sum+=val1;
    }
    average=float(sum)/(float)n2;
    cout << "\nSum of " << n << "Numbers :: " << sum << "\n";
    cout << "\n Average of " << n << "Numbers :: " << average << "\n"; 
    cout << "----------------------" << "\n";
    int n3,c1{6};
    cout << " please input the size of the array : ";
    cin >> n3;
    int arr[n3];
    cout << "please input the array : ";
    for(int w=0; w<n3;w++){
        cin >> arr[w];
    }
    cout << "The Elements of the array are ";
    for(int w=0; w<n3;w++){
        arr[w] *=c1;
        cout << arr[w] << " ";
    }
    cout << "\n-------------" << "\n";
    int arr2[] = {12,23,34,45,56,76,78,78},sums{0},n4{8};
    for(int s=0; s<n4;s++){
        sums+=arr2[s];
    }
    cout << "Sum :: " << sums; 
    cout << "-------------" << "\n";
    vector<int> v{23,34,45,56,56,55,36,24};
    int sumss{0};
    sumss = accumulate(v.begin(),v.end(),sumss);
    cout << "\n The sumss of the Array : " << sumss << "\n";
    int n6{12};
    cout << " ---------------------------------" << "\n";
    pascaltri(n6);
    return 0;
} 