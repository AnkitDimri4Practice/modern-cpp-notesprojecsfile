#include<iostream>
using namespace std;
void swap(int*, int*);
void sortarray(int*, int);
int main()
{
   int n;
   cout << "enter the size of the array : ";
   cin >> n;
   int arr[n];
   cout << "please enter all the elements of the array ";
   for(int i = 0; i<n;i++){
      cin >> arr[i];
   }
   cout << "Sorting .....";
   sortarray(arr, n);
   cout << " array is sorted now...";
   for(int i = 0; i<n; i++){
      cout << arr[i] << "\t";
   }
   cout << "\n";
   return 0;
}
void sortarray(int* arr, int size){
   for(int i = 0; i<size-1; i++){
      for(int j = i+1;j<size;j++){
         if(arr[i]<= arr[j]){
            continue;
         } else {
            swap(arr+i, arr+j);
         }
      }
   }
   return;
}
void swap(int* a, int* b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
   return;
}