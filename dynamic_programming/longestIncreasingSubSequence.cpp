#include <iostream>

using namespace std;


// using recursion
int longestIncreasingSubsequence(int arr[], int index, int size, int& max_ref){
	
	if(index == size - 1){
		cout<<"value returned at "<<arr[index]<<" is 1"<<endl;
		return 1;
	}
	
	int current_max;
	int max = 0;
	for(int i = index + 1; i < size; i++){
		if(arr[i] > arr[index]){
			current_max = longestIncreasingSubsequence(arr, i, size, max_ref) + 1;
			if(max < current_max){
				max = current_max;
			}
		}
	}
	cout<<"value returned at "<<arr[index]<<" is "<<max<<endl;
	return max;
}

void findSequence(int arr[], int size){
	
	int max = 1;
	int overallMax = 0;
	for(int i = 0; i < size; i++){
		cout<<"start with "<<arr[i]<<endl;
		max = longestIncreasingSubsequence(arr, i, size, max);
		
		if(overallMax < max ){
			overallMax = max;
		}
	}
	
	cout<<"longest common subsequence is "<<overallMax<<endl;
	return;
}


// using dynamic programming;
int longestIncreasingSubsequenceUsingDB(int arr[], int index, int size, int& max_ref){
	
	if(index == size - 1){
		return 1;
	}
	
	int current_max;
	int max = 0;
	for(int i = index + 1; i < size; i++){
		if(arr[i] > arr[index]){
			current_max = longestIncreasingSubsequence(arr, i, size, max_ref) + 1;
			if(max < current_max){
				max = current_max;
			}
		}
	}
	return max;
}

void findSequenceUsingDB(int arr[], int size){
	
	int max = 1;
	int overallMax = 0;
	for(int i = 0; i < size; i++){
		cout<<"start with "<<arr[i]<<endl;
		max = longestIncreasingSubsequence(arr, i, size, max);
		
		if(overallMax < max ){
			overallMax = max;
		}
	}
	
	cout<<"longest common subsequence is "<<overallMax<<endl;
	return;
}

int main(){
	
//	cin>>n;
//	int arr[n + 1];
	int arr[] = {3, 10, 2, 1, 20};
	int n = sizeof(arr) / sizeof(arr[0]);
	findSequence(arr, n);
	return 0;
	
}
