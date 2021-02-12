    #include <iostream>
    using namespace std;

    int maxSum(int a[], int len){

        for(int i = 1; i < len; i++){
            
            if(a[i-1] + a[i] > a[i]){
                a[i] = a[i-1] + a[i];
            }
        }
        int max = a[0];
        for(int i = 1; i < len; i++){
            if(max < a[i]) max = a[i];
        }
        return max;
    }

    int main(){
        int a[] = {5, -7, 8, 9};
        cout<<maxSum(a, 4);
        return 0;
    }