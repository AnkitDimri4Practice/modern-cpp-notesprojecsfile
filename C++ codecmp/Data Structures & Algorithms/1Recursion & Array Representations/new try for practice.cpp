#include<iostream>
using namespace std;
int Sum(int n){
    if(n==0){
        return 0;
    } else {
        return Sum(n-1)+n;
    }
}
int Fact(int n){
    if(n==0)
    return 1;
    else 
    return Fact(n-1)*n;
}
int Pow(int m,int n){
    if(n==0)
    return 1;
    else 
    return Pow(m,n-1)*n;
}
double main_1(int x, int n){
    static double p{1},f{1};
    double r;
    if(n==0){
        return 1;
    }
    else {
        r = main_1(x,n-1);
        p = p*x;
        f = f*n;
        return (r + p/f); 
    }
}
double main_2(int x,int n){
    static double s = 1;
    if(n==0){
        return s;
    } else {
        s = 1+x*s/n;
        return main_2(x,n-1);
    }
}
int main_3(int n){ 
    if(n<=1){
        return n;
    } else {
        return main_3(n-2)+main_3(n-1);
    }
}
int F[10];
int main_4(int n){
    if(n<=1){
        F[n]=n;
        return n;
    } else {
        if(F[n-2]==-1)
            F[n-2]=main_4(n-2);
        if(F[n-1]==-1)
            F[n-1]=main_4(n-1);
        return F[n-2] + F[n-1];
    }
}
// int C(int n, int r){
//     int t1,t2,t3;
//     t1=fact(n);
//     t2=fact(r);
//     t3=fact(n-r);
//     return t1/(t2*t3);
// }

int C(int n, int r){
    if(r==0 || n==r)
    return 1;
    else 
    return C(n-1,r-1)+C(n-1,r);
}
void TOH(int n,int a,int b,int c){
    if(n>0){
        TOH(n-1,a,c,b);
        // TOH(1,a,b,c); 
        cout <<a<<", "<<c<<"\n";
        TOH(n-1,b,a,c);
    }
}
int main(){
    // int x,n;cin>>x>>n;cout << "Summation : "<<Sum(n);
    // cout <<"\nFactorial : " << Fact(n);cout << "\nPower : " << Pow(x,n);cout << "\nTaylor Series : " << main_1(x,n);cout << "\nNew Recursive Functions :: "<<main_2(x,n);
    // int n_1;cin>>n_1;cout<<"\nFibonacci Series :: "<<main_3(n_1);
    // for(int i = 0;i<n_1; i++){
    //     F[i]=-1;
    // }
    // cout << "\nFibnoccai :: " << main_4(n_1);

    // int n,r;cin>>n>>r;cout << "The Valur of the the combination is :: " << C(n,r) << "\n";
    // TOH(5,2,3,4);

    int A[10];
    cout << "A :: ";
    for(int i = 0;i<10;i++){
        cout << A[i] << " ";
    }
    int B[5]={10,20,30,40,50};
    cout << "\nB :: ";
    for(int i=0;i<5;i++){
        cout << B[i] << " ";
    }
    cout << "\n";
    float C[5]={1.1,2.3};
    cout << "\nC :: ";
    for(int i = 0;i<5; i++){
        cout << C[i]<< " ";
    }
    cout << "\n";   
    return 0;
}

// n = 4.   1+x/1[1+x/2[1+x/3]]