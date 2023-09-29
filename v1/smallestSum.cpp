#include <iostream>
using namespace std;

int smallSumId(int arr[], int n){
	
	int res = 1;
	for(int i = 0; i < n && arr[i] <= res; i++){
		res += arr[i];
	}
	return res;
}

int main(){
	
	int arr1[] = {1,1, 3, 4, 5};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << smallSumId(arr1, n1) << endl;
   	return 0;
}
