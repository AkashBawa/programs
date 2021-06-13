#include <iostream>

using namespace std;

int findFibbonicNumber(int n, int arr[]){
	
	if(arr[n] != -1 ){
		return arr[n];
	}
	
	if(n == 1){
		arr[n] = 1;
		return 1;
	}
	if(n < 1){
		arr[n] = 0;
		return 0;
	}
	
	arr[n] = findFibbonicNumber(n - 1, arr) + findFibbonicNumber(n - 2, arr);
	return arr[n];
}

int main(){
	
	int n;
	cin>>n;
	int arr[n + 1];
	
	for(int i = 0; i <= n; i++){
		arr[i] = -1;
	}
	
	cout<<findFibbonicNumber(n, arr);
	return 0;
	
}
