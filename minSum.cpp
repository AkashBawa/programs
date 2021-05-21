#include <iostream>
using namespace std;

int getSmallCount(int a[], int n, int toCount){
	int ans = 0;
	int min = 9999999;
	for(int i = 0; i < n; i++){
		
		if(a[i] > toCount){
			return 1;
		}
		int sum = a[i];
		
		for(int j = i + 1; j < n; j++){
//			cout<<"sum is" <<sum<<endl;
//			cout<< " i and j "<<i << " "<<j<<endl;
			sum += a[j];
			if(sum > toCount && j - i + 1 < min){
				min = j - i + 1;
			}else if(sum > toCount){
				break;
			}
		}
	}
	return min;
}

int newWay(int a[], int n, int sum){
	
	int start = 0, end = 0;
	int minLen = n + 1;
	int count = 0;
	while(end < n){
		
		while(end < n && count < sum){
			count+= a[end++];
		}
		while(start < n && count > sum){
			
			if(minLen > end - start){
				minLen = end - start;
			}
			count -= a[start++];
		}
	}
	return minLen;
}

int main(){
	 
	int n = 6;
	int arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
	int count = 280;
	int smcount = getSmallCount(arr, n, count);
	cout<<smcount<<endl;
	
	cout<<newWay(arr, n , count);
	return 0;
	
}
