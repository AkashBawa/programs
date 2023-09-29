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
	
//	cout<<"longest common subsequence is "<<overallMax<<endl;
	return;
}


// using dynamic programming;
int longestIncreasingSubsequenceUsingDB(int arr[], int index, int size, int& max_ref, int list[]){
	
//	cout<<"list at index "<<index<<" is "<<list[index]<<endl;
//	if(list[index] != 0){
//		return list[index];
//	}
	if(index == size - 1){
		list[index] = 1;
//		cout<<"value returned at index "<<index<<" with value "<<arr[index]<<" is 1"<<endl;
		return 1;
	}

	int current_max;
	int max = 1;
//	for(int i = index + 1; i < size; i++){
//		if(arr[i] > arr[index]){
//			current_max = longestIncreasingSubsequenceUsingDB(arr, i, size, max_ref, list) + 1;
//			list[index] = current_max;
//			if(max < current_max){
//				max = current_max;
//			}
//		}
//	}

	for(int i = index + 1; i < size; i++){
		
		if(list[i] != 0){
			current_max = list[i];
//			cout<<" not null "<<current_max<<endl;
		} else {
			list[i] = longestIncreasingSubsequenceUsingDB(arr, i, size, max_ref, list);
			current_max  = list[i];
		}
		
		if(arr[index] < arr[i]){
			current_max++;
			
		}
		if(current_max > max){
			list[index] = current_max;
			max = current_max;
		}
	}	
//	cout<<"value returned at index "<<index<<" with value "<<arr[index]<<" is "<<max<<endl;
	return max;
}

void findSequenceUsingDB(int arr[], int size){
	
	int max = 1;
	int overallMax = 0;
	int list[size] = {0};
	for(int i = 0; i < size; i++){
//		cout<<"start with "<<arr[i]<<endl;
		max = longestIncreasingSubsequenceUsingDB(arr, i, size, max, list);
		list[i] = max;
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
	int arr[] = {3, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
//	findSequence(arr, n);
	findSequenceUsingDB(arr, n);
	return 0;
	
}
