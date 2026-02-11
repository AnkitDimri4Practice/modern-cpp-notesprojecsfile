#include<iostream>
using namespace std;
struct Array {
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    for(int i{0}; i<arr.length;i++){
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}
int LinearSearch(struct Array *arr, int key){
    for(int i{0};i<arr->length; i++){
        if(key==arr->A[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    struct Array arr = {{1,2,3,4,5,6},10,6};
    cout << "The searched element is found at position : " << LinearSearch(&arr, 4) << "\n";
    display(arr);
    return 0;
}
// C:\Windows\System32\WindowsPowerShell\v1.0\