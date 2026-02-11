//{ Driver Code Starts
// Initial template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int l = 0, mid, h = n-1;
        while(l<=h){
            mid = (l+h)/2;
            if(k==arr[mid]){
                return mid;
            }
            else if(k<arr[mid]){
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return -1;   
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cout << "Please enter the value : ";
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++){
            cin >> arr[i]; 
            cout << i << " : " << arr[i] << "\n";
        }  
        cout << "\nEnter the number which number you want to find in the input array : ";
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << "Key : " << found << endl;
    }
}