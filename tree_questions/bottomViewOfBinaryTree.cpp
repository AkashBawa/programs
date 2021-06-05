#include <iostream>
#include <queue>
#include <map>

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
//    
	
	if(isCompleteBinaryTree(start)){
		cout<<"complete binary tree";
	} else {
		cout<<"not complete binary tree";
	}
	

	return 0;
}

