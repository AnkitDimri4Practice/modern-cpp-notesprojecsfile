#include<iostream>
using namespace std;
struct Array {
    int A[10];
    int size;
    int length;
};
void display(struct Array arr){
    for(int i{0};i<arr.length;i++){
        cout << arr.A[i] << " ";
    }
    cout << "\n";
}
int BinarySearch(struct Array arr, int key){
    int l = 0, mid, h = arr.length;
    while(l<=h){
        mid = (l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return -1;
}
int main(){
    struct Array arr = {{1,23,4,5,6,7},10,6};
    cout << "\nThe index of key element is " << BinarySearch(arr,5) << "\n";
    display(arr);
    return 0;
}