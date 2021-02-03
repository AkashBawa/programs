// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int binarySearch(int a[], int len){
    int low = 0;
    int high = len - 1;
    int result = -1;
    
    while(low <= high){
        
        int mid = (high + low ) / 2;
        
        int previous = (mid - 1 + len) % len;   //  if mid if first then go to last so use module ; + len because mid - 1 do not goes negative
        
        int next = (mid + 1) % len;  // if mid is last, then do to first
        
        if(a[low] <= a[high]) {
            return low;
        }
        
        else if(a[mid] < a[next] &&  a[mid] < a[previous]){
            return  mid;
        } else if(a[mid] < a[high]){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    
    int a[] = {11,12,15,18,2,5,6,8};
    
    int len = sizeof(a) / sizeof(a[0]);
    
    int index = binarySearch(a, len);
    cout<<index;

    return 0;
}