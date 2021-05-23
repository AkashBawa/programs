// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>

using namespace std;

bool subset(int a[], int count, int left, int required, int index){
    if(count == required){
        return true;
    } 
    if(count + a[index] > required){
        return false;
    }
    if(left - a[index] < 0){
        return false;
    }
    
    if(subset(a, count + a[index], left - a[index], required, index + 1)){
        cout<<"value is : "<<a[index]<<endl;
        return true;
    }
    if(subset(a, count, left - a[index], required, index + 1)){
        return true;
    }
    
    return false;
}


int main() {
    
    int a[] = {5,10,12,13,15,18};
    int left = 0;
    for(int i = 0; i < 6; i++){
        left += a[i];
    }
    cout<<left<<endl;
    int required  = 73;
    if(subset(a, 0, left,required, 0 )){
        cout<<"contain subset";
    } else {
        cout<<"Not found";
    }
    
    return 0;
}