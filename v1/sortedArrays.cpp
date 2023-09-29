#include <iostream>
#include <vector>
#include<string>  
#include <sstream>


// Question : find all sorted array from given two sorted arrays constion , first element is always from first array and last elemnt is always from second array
using namespace std;
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

vector<string> getArrays(int a[], int b[] ,int m, int n, int current, int a_i, int b_i, vector<string>ans){
	
	if(a_i >= m || b_i >= n){
		return ans;
	}
	
	int ai = -1 , bi = -1;   // just to check if the element found or not
	
	for(int i = a_i; i < m; i++){
//		cout<<"inside a loop "<<endl;
		if(a[i] > current){
			current = a[i];
			a_i = i;
			ai = 1;
			break;
		}
	}
	if(ai == -1){		// no element grater than current found
		return ans;	
	}
	
	for(int i = b_i; i < n; i++){
//		cout<<"inside b loop "<<endl;
		if(b[i] > current){
			current = b[i];
			b_i = i;
			bi = 1;
			if(ans.size() == 0){
//				cout<<"inside if"<<endl;
				ans.push_back( patch::to_string(a[a_i])+ " " + patch::to_string(b[b_i]));
			} else {
				ans.push_back(ans.back() + " " + patch::to_string(a[a_i]) + " " + patch::to_string(b[b_i]) );
			}
			break;
		} 
	}
	
	if(bi == -1){		// no element greater than current found in b;
		return ans;
	}
	return getArrays(a, b, m, n, current, a_i + 1, b_i + 1, ans);
}




vector<string> usingSingle(int a[], int b[] ,int m, int n, int current, int a_i, int b_i, vector<string>ans , int flag, string s){  // flag == 0 means scan a and 1 means scan b;
	
	if(flag == 0){
		
		if(a_i >= m){
			return ans;
		}
		
		int ai = -1;   // just to check if the element found or not
	
		for(int i = a_i; i < m; i++){
//			cout<<"inside a loop "<<endl;
			if(a[i] > current){
				current = a[i];
				a_i = i;
				ai = 1;
				ans = usingSingle(a, b, m, n, current, a_i, b_i, ans, 1, s  + patch::to_string(a[a_i]) + " ");
			}
		}
		return ans;
		
		if(ai == -1){		// no element grater than current found
			return ans;	
		}
		
	} else if(flag == 1){
		
		int bi = -1;
		if(b_i >= n){
			return ans;
		}
		
		for(int i = b_i; i < n; i++){
			
			if(b[i] > current){
//				cout<<"inside b if loop"<<endl;
				current = b[i];
				b_i = i;
				bi = 1;
				
				string temp = s  + patch::to_string(b[b_i]) + " ";
				ans.push_back(temp);
				
				ans = usingSingle(a, b, m, n, current, a_i + 1, b_i + 1, ans, 0, temp);
			} 
		}
		return ans;
	}
}



void printArr(vector< vector<string> >a){
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++){
			cout<<a[i][j]<<endl;
		}
	}
	cout<<endl;
}

void singlePrint(vector <string>s){
	for(int j = 0; j < s.size(); j++){
			cout<<s[j]<<endl;
		}
}

int main() {
	
    int m = 3, n = 4;
    
    int a[m] = { 10, 15, 25};
    int b[n] = { 1, 5 , 20, 30};
    
    vector<string>ans;
    vector<string>response;
    vector< vector<string> > finAns;
	vector<string> finAns2;
	
//    for(int i = 0; i < m; i++){
    	response = usingSingle(a,b, m,n , 0 , 0, 0, ans, 0, "");
//    	finAns.push_back(response);
//    	response.clear();
//    	ans.clear();
//	}
	
	singlePrint(response);
    return 0;
}
