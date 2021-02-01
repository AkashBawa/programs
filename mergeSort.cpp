// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void merge(int a[], int size, int first, int mid, int last){
    
    int n1 = mid - first + 1;
    int n2 = last - mid;
    
    int left[n1];
    int right[n2];
    
    for(int i = 0; i < n1; i++){
        left[i] = a[first + i];
    }    
    for(int i = 0; i < n2; i++){
        right[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, current = first;
    while(i < n1 && j < n2){
        if(left[i] < right[j]){
            a[current] = left[i];
            i++;
            current++;
        } else {
            a[current] = right[j];
            j++;
            current++;
        }
    } 
    while(i < n1){
        a[current] = left[i];
        i++;
        current++;
    }
    while(j < n2){
        a[current] = right[j];
        current++;
        j++;
    }
}

void mergeSort(int a[], int size, int first, int last){
    int mid = first + (last - first) / 2;
    if(first < last){
        
        mergeSort(a, size, first, mid);
        mergeSort(a, size, mid + 1, last);
        merge(a, size, first, mid, last);
    } 
}

void print(int a[], int size){
    for(int i = 0; i < size; i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl;
}


int main() {
    // Write C++ code here
    int a[]=  {3, -9, 5, -1, 2, 6, 7, -10, -12};
    int size = sizeof(a) / sizeof(a[0]);
    print(a, size);
    mergeSort(a, size, 0, size - 1);
    print(a, size);
    return 0;
}