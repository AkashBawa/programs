#include <iostream>
using namespace std;

int findPivot(int arr[], int n, int start, int end){
	int mid = (end + start) / 2;
	
	if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
		return mid;
	} else {
		if(arr[start] > arr[mid]){			// pivot present on left side
			return findPivot(arr, n, start, mid - 1);	
									
		} else if(arr[mid] > arr[end]){		// pivot present on right side
			return findPivot(arr, n , mid + 1, end);
		}
	}
}

int binarySearch(int arr[], int n, int start, int end, int toFind){
	
	int mid = (end + start) / 2;
		
	if(arr[mid] == toFind){
		return mid;
	}
	if(start > end){
		return -1;
	}
	if(arr[mid] > toFind){
		return binarySearch(arr, n , start, mid - 1, toFind);
	} else if(arr[mid] < toFind){
		return binarySearch(arr, n ,  mid + 1, end,toFind);	
	}
}

int main(){
	int  arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
		
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int pivot = findPivot(arr, size, 0 , size - 1);
	
	int toFind = 8;
	int ans = -1;
	if(arr[pivot] == toFind){
		ans = pivot;
	}
	else if(arr[pivot] > toFind && arr[0] <= toFind){
		ans = binarySearch(arr, size, 0, pivot - 1, toFind);
	} else if(arr[pivot + 1] <= toFind && arr[size -1] >= toFind){
		ans = binarySearch(arr, size, pivot + 1, size - 1 , toFind);	
	}
	cout<<ans;
	
	return  0;
}
