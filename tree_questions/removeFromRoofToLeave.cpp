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

bool removeNodesofMinDistance(Node* current, int k, int count){
	
	if(count >= k){
		return false;
	}
	
	if(current->left != NULL){
		
		if(removeNodesofMinDistance(current->left, k, count + 1)){
			delete current->left;
			current->left = NULL;
		}
	}
	if(current->right != NULL){
		
		if(removeNodesofMinDistance(current->right, k , count + 1)){
			delete current->right;
			current->right = NULL;
		}
	}
	if(current->left == NULL && current->right == NULL){
		return true;
	} else {
		return false;
	}
}

int main(){

	Node *root = addNode(1);
    root->left = addNode(2);
    root->right = addNode(3);
    root->left->left = addNode(4);
    root->left->right = addNode(5);
    root->left->left->left = addNode(7);
    root->right->right = addNode(6);
    root->right->right->left = addNode(8);
    
    cout<<"Before deletion "<<endl;
    printNode(root);
    removeNodesofMinDistance(root, 4, 1);
    cout<<endl<<"After deletion"<<endl;
	printNode(root);
	
	return 0;
}	
