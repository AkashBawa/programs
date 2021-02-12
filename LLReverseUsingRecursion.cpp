<<<<<<< HEAD
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node* next;
};

void insert(Node* root, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    
    while(root->next != NULL ){
        root = root->next;
    }
    
    root->next = temp;
}

void print(Node* root){
    
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}

bool printR(Node* root){
    if(root == NULL){
        
        return true;
    }else {
        if(printR(root->next)){
            cout<<root->data<<" ";
            return true;
        }
    }
}

Node* reverse(Node* root){
    
    Node* previous = root;
    Node* next = root->next;
    root->next = NULL;
    
    while(next != NULL){
        root = next;
        
        next = root->next;
        
        root->next = previous;
        
        previous = root;
        
    }
    return root;
}

Node* head;
void reverseR(Node* current){
    if(current->next == NULL){
        head = current;
        return;
    } else{
        // Node* nextN = reverseR(root->next);
        // nextN->next = root;
        // return root;
        reverseR(current->next);
        Node* tempN = current->next;
        tempN->next = current;
        current->next = NULL;
    }
}
int main() {
    
    Node* root = new Node();
    root->data = 1;
    root->next = NULL;
    insert(root, 5);
    insert(root, 10);
    insert(root, 15);
    insert(root, 20);
    // printR(root);
    reverseR(root);
    print(head);
    // Node* root1 = reverse(root);
    // print(root1);
    return 0;
=======
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public : 
        int data;
        Node* next;
};

void insert(Node* root, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    
    while(root->next != NULL ){
        root = root->next;
    }
    
    root->next = temp;
}

void print(Node* root){
    
    while(root != NULL){
        cout<<root->data<<" ";
        root = root->next;
    }
    cout<<endl;
}

bool printR(Node* root){
    if(root == NULL){
        
        return true;
    }else {
        if(printR(root->next)){
            cout<<root->data<<" ";
            return true;
        }
    }
}

Node* reverse(Node* root){
    
    Node* previous = root;
    Node* next = root->next;
    root->next = NULL;
    
    while(next != NULL){
        root = next;
        
        next = root->next;
        
        root->next = previous;
        
        previous = root;
        
    }
    return root;
}

Node* head;
void reverseR(Node* current){
    if(current->next == NULL){
        head = current;
        return;
    } else{
        // Node* nextN = reverseR(root->next);
        // nextN->next = root;
        // return root;
        reverseR(current->next);
        Node* tempN = current->next;
        tempN->next = current;
        current->next = NULL;
    }
}
int main() {
    
    Node* root = new Node();
    root->data = 1;
    root->next = NULL;
    insert(root, 5);
    insert(root, 10);
    insert(root, 15);
    insert(root, 20);
    // printR(root);
    reverseR(root);
    print(head);
    // Node* root1 = reverse(root);
    // print(root1);
    return 0;
>>>>>>> master
}