#include <iostream>

using namespace std;

// find pytharogras triplet means array like 	int arr[] = { 3, 1, 4, 6, 5 }; here we have 3^2 + 4^2 = 5^2 
// so this is pythagoras triplet

void bubbleSort(int a[], int n){
	
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j+1] = temp;
			}
		}
	}
}

bool isPythgoralTriplet(int arr[], int n){
	
	for(int i = 0; i < n - 1; i++){
		
		int start = 0;
		int end = n - 2 - i;
		while(start < end){
			
			int val = arr[start] * arr[start] + arr[end] * arr[end];
			int toCompare = arr[n-1-i] * arr[n-1-i];
			if(val == toCompare){
				return true;
			} else if( val > toCompare) {
				end--;
			} else {
				start ++;
			}
		}
	}
	return false;
	
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<"	";
	}
	cout<<endl;
}

int main(){
	
//	int arr[] = { 3, 1, 4, 6, 5 };
	int arr[] = {10, 4, 6, 12, 5} ;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	bubbleSort(arr, n);
	printArr(arr, n);
	if(isPythgoralTriplet(arr, n)){
		cout<<"has triplet";
	} else {
		cout<<"No triplet found";
	}
	
	return  0;
}
