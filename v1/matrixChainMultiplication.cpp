#include <iostream>
using namespace std;

int findMinCost(int a[], int len){
    int arr[len][len];
    int col = 0;
    for(int i = 0; i < len; i++){
        arr[i][i] = 0;
    }
    
    for(int i = 0; i < len; i++){

        for(int j = 0; j < len - i; j++){

        }
    }
}

int main(){
    int a[] = { 1, 2, 3, 4 };
    int len = sizeof(a) / sizeof(a[0]);
    
    cout<<findMinCost(a, len);
}