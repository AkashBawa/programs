#include <iostream>
#include <queue>
#include <map>
#define MAX 100
using namespace std;

class Node {
	public : 
		char value;
		Node *left;
		Node *right;
};

Node* newNode(int value){
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

void printArr(char arr[], int size){
	for(int i = 0; i < size; i++){
		if(arr[i] == NULL){
			cout<<endl;
			return;
		}
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int getInOrder(Node* current, char arr[], int index){

	arr[index] = current->value;
	if(current->left){
		index = getInOrder(current->left, arr ,index + 1);	
	}
	if(current->right){
		index = getInOrder(current->right, arr ,index + 1);
	}
	return index;
}

void preOrder(Node* current, char arr[], int& index){
	
	if(current->left){
		preOrder(current->left, arr, index);
	}
	arr[index] = current->value;
	index++;
	if(current->right){
		preOrder(current->right, arr, index);
	}
}

bool compareArray(char a[], char b[]){
	
	int i = 0;
	int j = 0;
	
	while (j < MAX){
		
		if(i == MAX && j != MAX){
			return false;
		}
		if(j >= MAX || b[j] == NULL ){
			return true;
		}
		
		if(a[i] == b[j]){
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	return false;
	
}

bool isSubTree(Node* main, Node* second){
	
	char preA[MAX];
	char inorderA[MAX];
	
	char preB[MAX];
	char inorderB[MAX];
	
	// getting both array inOrder
	getInOrder(main, inorderA, 0);
	getInOrder(second, inorderB, 0);
	
	//getting both array in preOrder
	int index = 0;
	preOrder(main, preA, index);
	index = 0;
	preOrder(second, preB, index);
	
	if(!compareArray(inorderA, inorderB)){
		return false;
	}
	if(!compareArray(preA, preB)){
		return false;
	}
	return true;
	
}

int main(){
	
	// example 1
	Node* T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node* S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');

	
	if(isSubTree(T, S)){
		cout<<"complete binary tree";
	} else {
		cout<<"not complete binary tree";
	}
	
	return 0;
}

