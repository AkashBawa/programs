// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int quickSort(int a[], int len, int start, int end){
    
    int pivot = a[end];
    
    int  i = start - 1;
    
    for(int j = start; j <= end; j++){
        
        if(a[j] < pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[end];
    a[end] = a[i + 1];
    a[i + 1] = temp;
    return i;   
}

void partition(int a[], int len, int start, int end){
    
    
    if(start < end){
        int p = quickSort(a, len, start, end);
        partition(a, len, start, p);
        partition(a, len , p + 1, end);
    }
}

void print(int a[], int len){
    for(int i = 0; i < len; i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl;
}

int main() {
    
    int a[] = {10, 80, 30, 90, 40, 50, 70};
    int len = sizeof(a) / sizeof(a[0]);
    partition(a, len, 0, len - 1);
    print(a, len);
    return 0;
}