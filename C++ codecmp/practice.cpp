#include<iostream>
using namespace std;
float D(float n, float m){
    cout << "enter two numbers : "; 
    cin >> m >> n;
    if(n<0 && m<0)
    return 1;
    else 
    cout << "Sum : ";
    return m+n;
}
int main(){
    float n,m,p;cout<< D(m,n) << "\n";
    cin>>p;
    for(int i{1}; i<=p;i++){
        cout << i << " :: "<< D(m,n) << "\n";
    }
    return 0; 
}