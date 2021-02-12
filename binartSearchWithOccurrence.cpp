<<<<<<< HEAD
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int binarySearch(int a[], int len, int toFind){
    int low = 0;
    int high = len - 1;
    int result = -1;
    while(low <= high){
        int mid = (high + low ) / 2;
        if(a[mid] == toFind){
            result = mid;
            // high = mid - 1;     // to find the first occurence
            low = mid + 1;      // to find the last occurence
        } else if(a[mid] < toFind){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    
    int a[] = {1,2,3,3,3,3,3,4,5,6,7,8,9,10,10,10,10,10,12,16,16,16,17};
    
    int len = sizeof(a) / sizeof(a[0]);
    
    int index = binarySearch(a, len , 1);
    if(index >= 0){
        cout<<index;
    } else{
        cout<<"Not found";
    }

    return 0;
=======
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int binarySearch(int a[], int len, int toFind){
    int low = 0;
    int high = len - 1;
    int result = -1;
    while(low <= high){
        int mid = (high + low ) / 2;
        if(a[mid] == toFind){
            result = mid;
            // high = mid - 1;     // to find the first occurence
            low = mid + 1;      // to find the last occurence
        } else if(a[mid] < toFind){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    
    int a[] = {1,2,3,3,3,3,3,4,5,6,7,8,9,10,10,10,10,10,12,16,16,16,17};
    
    int len = sizeof(a) / sizeof(a[0]);
    
    int index = binarySearch(a, len , 1);
    if(index >= 0){
        cout<<index;
    } else{
        cout<<"Not found";
    }

    return 0;
>>>>>>> master
}