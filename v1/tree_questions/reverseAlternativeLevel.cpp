#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Node {
	public : 
		char value;
		Node *left;
		Node *right;
};

Node* newNode(char value){
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

void treeTraverse(Node* current, int level, stack<char>&s){
	
	if(current == NULL){
		return;
	}
	treeTraverse(current->left, level + 1, s);
	
	if(level % 2 == 0){		// odd level
//		cout<<"to be pushed "<<current->value<<endl;
		s.push(current->value);
	}
	treeTraverse(current->right, level + 1, s);
	return;
}

void assignReverse(Node* current, int level, stack<char>&s){
	
	if(current == NULL){
		return;
	}
	
	assignReverse(current->left, level + 1, s);
	
	if(level % 2 == 0){		// odd level
		
		char temp = s.top();
//		cout<<"temp is "<< temp<<endl;
//		cout<<"current value is "<<current->value<<endl;
		s.pop();
		current->value = temp;
	}
	assignReverse(current->right, level + 1, s);
	return;
}


void reverseAlternative(Node* start){
	
	cout<<"Before assignment"<<endl;
	printInLevelOrder(start);
	cout<<endl<<endl;
	
	stack<char> s;
	
	treeTraverse(start, 1, s);
	
	cout<<"size is "<<s.size()<<endl;
	assignReverse(start, 1, s);
	
	cout<<"after assignment"<<endl;
	printInLevelOrder(start);
}

int main(){
	
	Node* root = newNode('a');
	root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o');

	reverseAlternative(root);
	
	return 0;
}

