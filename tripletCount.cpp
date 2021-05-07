// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void sortArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j +1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n){
    for(int  i = 0; i < n; i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}

// find total triplet count less than given number in the array;

int findCount(int arr[], int n, int sum){
    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            if(arr[i] + arr[j] + arr[k] >= sum){
                k--;
            } else {
                ans += k - j;
                j++;
            }
        }
    }
    return ans;
}

int main() {
    int arr[] = {5, 1, 3, 4, 7};
    sortArr(arr, 5);
    printArr(arr, 5);
    cout<<findCount(arr, 5 , 12);
    return 0;
}