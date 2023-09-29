#include <iostream>
#include <queue>
using namespace std;


class Node {
	public : 
	int value;
	Node *left;
	Node *right;
};

 
Node* addNode(int value){
	Node *temp  = new Node();
	temp->value = value;
	return temp;
}

void printNode(Node* start){		// depth first scan
	if(start == NULL){
		return;
	} else {
		printNode(start->left);
		cout<<start->value<<" ";
		printNode(start->right);	
	}
}

void printInLevelOrder(Node* start){	// breath first scan
	
	cout<<endl;
	queue<Node*>q;
	q.push(start);
	while(q.empty() == false){
		
		Node* temp = q.front();
		cout<<temp->value<<" ";
		q.pop();
		
		if(temp->left){
			q.push(temp->left);
		} 
		if(temp->right)
			q.push(temp->right);
	}
	cout<<endl;
}

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

bool compareInoderArray(Node* start, int arr[] ,int &index){	// breath first scan

	if(start == NULL){
		return true;
	}
	else {
		
		if(compareInoderArray(start->left, arr, index) == false){
			return false;
		}
		
		cout<<"index is "<<index<<endl;
		cout<<"strat value "<<start->value <<" index value "<<arr[index]<<endl<<endl; 
		if(arr[index] !=  start->value){
			return false;
		}
		index++;
		if(!compareInoderArray(start->right, arr, index)){
			return false;
		}
		return true;
			
	}
}

bool comparePreoderArray(Node* start, int arr[] ,int &index){	// breath first scan

	if(start == NULL){
		return true;
	}
	else {
		
		cout<<"index is "<<index<<endl;
		cout<<"strat value "<<start->value <<" index value "<<arr[index]<<endl<<endl; 
		if(arr[index] !=  start->value){
			return false;
		}
		index++;
		
		if(comparePreoderArray(start->left, arr, index) == false){
			return false;
		}
		
		if(!comparePreoderArray(start->right, arr, index)){
			return false;
		}
		return true;
			
	}
}

int main(){

	// example 1
	Node* start = addNode(20);
	start->left = addNode(2);
	start->right = addNode(10);
	start->left->left = addNode(20);
	start->left->right = addNode(1);
    start->right->right = addNode(-25);
    start->right->right->left = addNode(3);
    start->right->right->right = addNode(4);
    
	
	int inOrderarr[] = {20,2,1,20,10,3,-25,4};
	int preOrder[] = {20,2,20,1,10,-25,3,4};
	int index = 0;
	
	
	if(comparePreoderArray(start,preOrder, index)){
		cout<<"array represent pre order "<<endl;
	} else {
		cout<<"array does not represent pre order";
	}
	
	return 0;
}

