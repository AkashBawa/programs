// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;
#define size 5

void print(int a[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool isSafe(int a[size][size], int row, int col){
    
    // upward
    for(int i = row; i >= 0; i--){
        if(a[i][col]){
            return false;
        }
    }
    
    //left
    for(int i = col; i >= 0; i--){
        if(a[row][i]){
            return false;
        }
    }
    
    // right
    for(int i = col; i < size; i++){
        if(a[row][i]){
            return false;
        }
    }
    
    // downward
    for(int i = row; i < size; i++){
        if(a[row][i]){
            return false;
        }
    }
    
    // upper left diagonal;
    
    for(int i = row,  j = col ; i >=  0 && j >= 0; i--, j--){
          if(a[i][j]){
            return false;
        } 
    }
    
    // lower right
    for(int i = row, j = col ; i < size && j < size ; i++, j++){
          if(a[i][j]){
            return false;
        }
    }
    
    // lower left
    for(int i = row, j = col ; i < size && j >= 0 ; i++, j--){
          if(a[i][j]){
            return false;
        }
    }
    
    //upper right
    for(int i = row, j = col ; i >= 0 && j < size ; i--, j++){
          if(a[i][j]){
            return false;
        }
    }
    return true;
}

bool getSolution(int a[size][size], int col){
    
    if(col >= size){
        return true;
    }
    
    for(int i = 0; i < size; i++){
        
        if(isSafe(a, i, col)){
            a[i][col] = 1;
            if(getSolution(a, col + 1)){ 
                return true;
            } 
            a[i][col] = 0;
        }
    }
    return false;
}

void solveNQ(int a[size][size]){
    bool allPlaced = getSolution(a, 0);
    
    if(allPlaced){
        print(a);
    } else {
        cout<<"no solution find";
    }
}

int main() {

    int a[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            a[i][j] = 0;
        }
    }
    solveNQ(a);
    return 0;
}