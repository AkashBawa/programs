#include <iostream>
#include <math.h>
using namespace std;

void findClosePair(int arr[], int size, int elem){
	
	int i = 0;
	int j = size - 1;
	int diff = -1;
	int first = -1, second = -1;
	while(i < j){
		int sum = arr[i] + arr[j];
		int newDiff = abs(sum - elem);
		
		if(newDiff < diff || diff == -1){
			diff = newDiff;
			first = arr[i];
			second = arr[j];
		} 
		
		if(sum == elem)
			break;
		if(sum > elem){
			j--;
		} else {
			i++;
		}
	}
	cout<<"elements are "<<first<<" "<<second<<endl;
	cout<<"minimum difference is "<<diff<<endl;
	
}

int main(){

	int arr[] = {1, 3, 4, 7, 10};
	int size = sizeof(arr)/ sizeof(arr[0]);
	findClosePair(arr, size, 15);
	return 0;	
}
