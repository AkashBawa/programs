#include <iostream>
using namespace std;

int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,5};
	
	int size = sizeof(arr)/ sizeof(arr[0]);
	int height = 0;
	while(size > 1){
		height++;
		size = size / 2;
	}
	cout<<"height is "<< height<<endl;
	return 0;
}
