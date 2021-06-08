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

int lowestCommonAncestor(Node* current,int low, int high){
	
	if(current->value == low || current->value == high)
		return current->value;
	
	if(current->value > low && current->value < high)
		return current->value;
	
	if(current->value > high){
		return lowestCommonAncestor(current->left, low, high);
	} else if(current->value < low){
		return lowestCommonAncestor(current->right, low, high);
	}
	
}

int main(){
	
	// example 1
	Node *root  = addNode(20);
    root->left = addNode(8);
    root->right = addNode(22);
    root->left->left = addNode(4);
    root->left->right = addNode(12);
    root->left->right->left  = addNode(10);
    root->left->right->right = addNode(14);

 	int n1 = 14, n2 = 8;
 	int low, high;
 	if(n1 > n2){
 		low = n2;
 		high = n1;
	 } else{
	 	low = n1;
	 	high = n2;
	 }
 	
	cout<<lowestCommonAncestor(root, low, high);

	return 0;
}

