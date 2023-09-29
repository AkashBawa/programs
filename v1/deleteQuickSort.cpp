#include <iostream>
using namespace std;

void print(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int arr[], int size, int start, int end){
	
	if(start < end){
		
		int index = start;
		int i = start, j = start + 1;
		int pivot = arr[start];
		while(j <= end){
			if(pivot > arr[j]){
				i++;
				swap(arr[i], arr[j]);
			}
			j++;
		}
		swap(arr[start], arr[i]);
		quickSort(arr, size, start, i - 1);
		quickSort(arr, size, i + 1, end);
	}
	
}


int main(){
	int arr[] = {10,7,8,9,1,5};	
	int n = sizeof(arr) / sizeof(arr[0]);
	
	quickSort(arr, n, 0, n - 1);
	print(arr, n);
	return 0;
}
