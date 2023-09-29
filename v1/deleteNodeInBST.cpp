#include <iostream>
using namespace std;

class Node {
    public : 
        int data;
        Node* left;
        Node* right;
};

Node* newNode(int data) { 
    Node* node = new Node();
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
 
    return(node); 
}

Node* findMin(Node* current){
    cout<<"in find min"<<endl;
    cout<<current->data;
    if(current->left == NULL) return current;
    else return findMin(current->left);
}

Node* deleteNode(Node* root, int data){
    
    // case 1 
    if(root == NULL) return root;
    else if(data > root->data){
        cout<<"large data"<<endl;
        return deleteNode(root->right, data);
    } 
    else if(data < root->data){
        cout<<"small data"<<endl;
         return deleteNode(root->left, data);
    }
    else {
        // case 2  No child; delete leaf node
        if(root->left == NULL && root->right == NULL){
            cout<<"No child"<<endl;
            delete root;
            root = NULL;
            return root;
        } 
        // case 3 , only right child
        else if(root->left == NULL){
            cout<<"right child"<<endl;
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        } 
        // case 4 , only left child
        else if(root->right = NULL){
            cout<<"left child"<<endl;
            Node* temp = root;
            root = root->left;
            delete temp;
            return root; 
        }
        else {
            cout<<"both child"<<endl;
            cout<<root->right->data<<endl;
            Node* temp = findMin(root->right);
            cout<<temp->data<<endl;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
}

void printLevelOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    printLevelOrder(root->left);
    printLevelOrder(root->right);
}

int main() 
{ 
    Node *root = newNode(12); 
    root->left = newNode(4); 
    root->right = newNode(15); 
    root->left->left = newNode(3); 
    root->left->right = newNode(7); 
    root->left->right->right = newNode(9);
 
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
    cout<<endl;
    root = deleteNode(root,4);
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
    
 
    return 0; 
} 