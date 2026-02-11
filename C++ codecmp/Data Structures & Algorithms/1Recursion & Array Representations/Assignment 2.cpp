#include<iostream>
void HeadFn(int n)
{
    if(n > 0)
    {
        HeadFn(n-1); 
        std::cout << n << " ";
    }
}
int main()
{
    HeadFn(7);
    return 0;
}
#include<iostream>
void TailFn(int n){
    if(n > 0){
        std::cout << n << " ";  TailFn(n-1); 
    }
}
int main(){
    TailFn(5);
    return 0;
}
#include<iostream>
int Recur_Sum(int n){
	if (n <= 1)
	return 1;
	return n + Recur_Sum(n - 1);
}
int main(){
	int n;std::cout << "Enter the digit : ";std::cin>>n;
    std::cout <<"Sum : "<<Recur_Sum(n);
	return 0;
}
