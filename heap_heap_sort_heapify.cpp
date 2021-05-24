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

void deleteAndArrangeNode(int arr[], int size, int index){

	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * index + 2;
//	cout<< " left and right index "<<leftIndex<<" "<<rightIndex<<endl; 	
	if(rightIndex < size){					// node has both left and right child
		
		int maxIndex = arr[leftIndex] > arr[rightIndex] ? leftIndex : rightIndex;
		
		if(arr[index] < arr[maxIndex]){
			swap(arr[index], arr[maxIndex]);
			deleteAndArrangeNode(arr, size, maxIndex);
		}
		
		
	} else if(leftIndex < size){			// node has only left child
		
		if(arr[index] < arr[leftIndex]){
			swap(arr[index], arr[leftIndex]);
			return;
		}
	} else {									// end reached	
		return ;
	}
}

void heapSort(int arr[], int size){
	
	for(int i = 0; i < size; i++){
		
		swap(arr[0], arr[size - 1 - i]);
		deleteAndArrangeNode(arr, size - i - 1, 0);
		print(arr, size);
	}

}

// creating max heap
void createHeap(int arr[],int index){
	if(index <= 0){
		return;
	}
	
	int parentIndex = -1;
	if(index % 2 != 0){
		parentIndex = index / 2;
	} else {
		parentIndex = index / 2 - 1;
	}
	
	if(arr[parentIndex] < arr[index]){
		swap(arr[parentIndex], arr[index]);
	}
	createHeap(arr, parentIndex);
}



int main(){
	int n;
	cout<<"enter size of heap ";
	cin>>n;
	cout<<"enter element of heap"<<endl;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		createHeap(arr, i);
	}
	
	heapSort(arr, n);
	print(arr, n);
	return 0;
}
