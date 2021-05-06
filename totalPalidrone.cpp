// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printPalidrome(string subString, int len){
    int start = 0, end = len - 1;
    bool flag = true;
    while(start < end){
        if(subString[start] != subString[end]){
            flag = false;
            break;
        }
        start++;
        end--;
    }
    if(flag == true){
        cout<<subString<<endl;
    }
    
}

int main() {
    
    string s = "nitin";
    
    int len = s.length();
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - i; j++){
            printPalidrome(s.substr(j, i + 1), i + 1);
        }
    }
    return 0;
}