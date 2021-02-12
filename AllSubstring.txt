// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printString(string s, int clen, int tlen){
    for(int i = 0; i < tlen; i++){
        if(i + clen > tlen){
            break;
        }
        for(int j = 1; j <= clen; j++){
            cout<<s[j-1 + i];
        }
        cout<<endl;
    }
}

int main() {
    
    string s = "abcd";
    cout<<s.size();
    int len = s.size();
    cout<<len<<endl;
    for(int i = 1; i <= len; i++){
        printString(s, i, len);
    }
    return 0;
}