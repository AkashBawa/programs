#include <iostream>
#include <queue>
using namespace std;

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

bool comparePreoderArray(int arr[] ,int index, int size){	// breath first scan

	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * index + 2;
	
	cout<<"index "<<index<< " leftIndex "<<leftIndex<<"  rightIndex  "<<rightIndex<<endl;
		
	if(rightIndex < size){ // node has both children
		
		if(arr[leftIndex] > arr[index] || arr[rightIndex] < arr[index]){
			return false;
		} else {
			
			
			if(!comparePreoderArray(arr, leftIndex, size)){
				return false;
			} 
			if(!comparePreoderArray(arr, rightIndex, size)){
				return false;
			}
			return true;
		}
		
		
	} else if(leftIndex < size){ // node has only one children
		
		if(!comparePreoderArray(arr, leftIndex, size)){
			return false;
		} 
		return true;
	} else {
		return true;
	}
}

int main(){
	
	int arr[] = {2, 4, 3};
	int index = 0;
	int size = sizeof(arr)/sizeof(arr[0]);
	if(comparePreoderArray(arr, index, size)){
		cout<<"array represent pre order "<<endl;
	} else {
		cout<<"array does not represent pre order";
	}
	
	return 0;
}

