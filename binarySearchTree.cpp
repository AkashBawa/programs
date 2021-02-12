// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public :
        
        int data;
        Node* left;
        Node* right;
};

Node* getNewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

Node* insert(Node* root, int data){
    if(root == NULL){
        root = getNewNode(data);
    } else if(data <= root->data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
};

bool find(Node* root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    } else if(data < root->data) {
        return find(root->left, data);
    } else{
        return find(root->right, data);
    }
}

bool checkLeft(Node* current){
    if(current->left == NULL || current->left->data <= current->data)
        return true;
    else 
        return false;
}
bool checkRight(Node* current){
    if(current->right == NULL || current->right->data >= current->data)
        return true;
    else 
        return false;
}

bool isBinary(Node* current){
    if(current == NULL) return true;
    else if(checkLeft(current) && checkRight(current) && isBinary(current->left) && isBinary    (current->right)){
        return true;
    } else{
        return false;
    }
}

int main() {
    
    Node* root;
    root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 18);
    root = insert(root, 7);
    root = insert(root, 30);
    cout<<"insertion complete"<<endl;
    if(find(root, 30)){
        cout<<"find";
    }else {
        cout<<"not find";
    }
    return 0;
}