#include <iostream>
using namespace std;

int maxProfit(int arr[]){
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int current = -1;
	bool isBought = false;
	
	int profit = 0;
	
	for(int i = 0; i < size - 1; i++){
		if(arr[i] < arr[i+1] && isBought == false){
			current = arr[i];
			isBought = true;
		} 
		else if(arr[i] < arr[i+1]){
			continue;
		}
		else if(arr[i] < arr[i + 1]) {
			if(isBought == true){
				profit += arr[i + 1] - current;
				current = 0;
				isBought = false;
			} 
			else {
				continue;
			}
		}
	}
	if(isBought == true){
		profit  += arr[size - 1] - current;
	}
	return profit;
}


int maxProfit(int arr[], int n){
	
	int max = 0;
	int isBuy = 0;
	int current = arr[0];
	int profit = 0;
	
	for(int i = 1; i < n; i++){
		
		if(arr[i] > current){
			profit += arr[i] - current;
			current = arr[i];
		}
		current = arr[i];
	}
	return profit;
}

int main(){
	
//	int arr[] = {100,180,260,310,40,535,695};
	int arr[] = {7,1,5,3,6,4};	
	
	int size = sizeof(arr) / sizeof(arr[0]);
	cout<<maxProfit(arr, size);
	return 0;
}
