// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here

    int a[4][4] = 
    {
        {2, 4,6,8},
        {5,9,12,16},
        {2,11,5,9},
        {3,2,1,8}
    };
    int row_start = 0;
    int row_end = 4;
    int col_start = 0;
    int col_end = 4;
    int dir = 0;          // 0 means right ; 1 means down; 2 means left; 3 means up;
    while(row_start < row_end){
        // cout<<"0"<<endl;
        if(dir == 0){
            for(int i = col_start; i < col_end; i++){
                cout<<a[row_start][i]<<" ";
            }
            // cout<<endl;
            row_start++;
            dir = 1;
            
        }
        
        if(dir == 1){
            // cout<<"1"<<endl;
            for(int i = row_start; i < row_end; i++){
                cout<<a[i][col_end - 1]<<" ";
            }
            col_end--;
            // cout<<endl;
            dir = 2;
        }
        if(dir == 2){
            // cout<<"2"<<endl;
            for(int i = col_end - 1; i >= col_start; i--){
                cout<<a[row_end - 1][i]<<" ";
                // cout<<endl;
            }
            // cout<<endl;
            row_end--;
            dir = 3;
        }
        if(dir == 3){
            // cout<<"3"<<endl;
            for(int i = row_end - 1; i>= row_start; i--){
                cout<<a[i][col_start]<<" ";
                
            }
            col_start++;
            // cout<<endl;
            dir = 0;
        }
    }
    return 0;
}