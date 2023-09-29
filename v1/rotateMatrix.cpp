// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

const int N = 5;
const int n = N - 1;
void rotateMatrix(int arr[N][N]){
    for(int i = 0; i < n / 2; i++){
        
        for(int j = 0; j < (N - (2*i) - 1); j++){
            
            
            int temp = arr[i][j + i];
            arr[i][j + i] = arr[j+i][n - i];
            arr[j+i][n-i] = arr[n-i][n-i-j];
            arr[n-i][n-i-j] = arr[n-i-j][i];
            arr[n-i-j][i] = temp;
            
        }
    }
}

void printMatrix(int arr[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<arr[i][j]<<"      ";
        }
        cout<<endl;
    }
}

int main() {
    // Write C++ code here

    int arr[N][N] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    rotateMatrix(arr);
    printMatrix(arr);
    return 0;
}