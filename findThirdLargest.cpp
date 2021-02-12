<<<<<<< HEAD
#include <iostream>
using namespace std;

int randomMax(int a[], int number, int len){
    number = 3;
    int first = a[0];
    int second = 0;
    int third = 0;

    for(int i = 1; i < len; i++){

        if(a[i] > first){
            third = second;
            second = first;
            first = a[i];
        } else if(a[i] > second){
            third = second;
            second = a[i];
        } else if(a[i] > third){
            third = a[i];
        }
    }
    return third;

}

int main(){
    int a[] = {12, 13, 1, 10, 34, 16, 14}; 
    cout<<randomMax(a, 3, sizeof(a)/sizeof(a[0]));
    return 0;
=======
#include <iostream>
using namespace std;

int randomMax(int a[], int number, int len){
    number = 3;
    int first = a[0];
    int second = 0;
    int third = 0;

    for(int i = 1; i < len; i++){

        if(a[i] > first){
            third = second;
            second = first;
            first = a[i];
        } else if(a[i] > second){
            third = second;
            second = a[i];
        } else if(a[i] > third){
            third = a[i];
        }
    }
    return third;

}

int main(){
    int a[] = {12, 13, 1, 10, 34, 16, 14}; 
    cout<<randomMax(a, 3, sizeof(a)/sizeof(a[0]));
    return 0;
>>>>>>> master
}