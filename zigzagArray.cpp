// Online C++ compiler to run C++ program online

// print array in a < b > c < d > e <  this format in o(n)
#include <iostream>
using namespace std;

void swap(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    // Write C++ code here
    int a[] = {4, 3, 7, 8, 6, 2, 1};
    int size = sizeof(a) / sizeof(a[0]);
    
    for(int i = 0; i < size - 1; i++){
        
        if(i % 2 == 0){
            // element at i should be less than the next element
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
            }
        } else {
            if(a[i] < a[i+1]){
                swap(a[i], a[i+1]);
            }
            // element at i should be greater then the next element
        }
    }
    
    print(a,size);
    
    
    return 0;
}