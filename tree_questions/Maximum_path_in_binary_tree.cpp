#include <iostream>
#include <queue>
using namespace std;



class Node {
	public : 
	int value;
	Node *left;
	Node *right;
};

int findMaxSumPath(Node*);

Node* addNode(int value){
	Node *temp  = new Node();
	temp->value = value;
	return temp;
}

void printNode(Node* start){		// depth first scan
	if(start == NULL){
		return;
	} else {
		cout<<start->value<<" ";
		printNode(start->left);
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

int main(){
	Node* start = addNode(10);
	start->left = addNode(2);
	start->right = addNode(10);
	start->left->left = addNode(20);
	start->left->right = addNode(1);
    start->right->right = addNode(-25);
    start->right->right->left = addNode(3);
    start->right->right->right = addNode(4);

//	printNode(start);
//	printInLevelOrder(start);
	
	cout<<findMaxSumPath(start);
	return 0;
}

int findMaxSumPath(Node* current){
	
	int leftSum = 0;
	int rightSum = 0;
	if(current->left){
		leftSum = findMaxSumPath(current->left);
	}
	if(current->right){
		rightSum = findMaxSumPath(current->right);
	}
	
	int greater = rightSum > leftSum ? rightSum : leftSum;
	
	int total = current->value + greater;
	
	cout<<" total is "<<total<<" at node "<< current->value<<endl;
	if(total > 0){
		return total;
	} 
	else return 0;
}	













