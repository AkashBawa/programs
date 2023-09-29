#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* createNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void removeLoop(Node* root, Node* intersection){
    Node* slow = root;

    while(slow->next != intersection->next){
        slow = slow->next;
        intersection = intersection->next;
    }
    intersection->next = NULL;
}

void detectLoop(Node* root){
    Node* slow = root;
    Node* fast = root;
    Node* current = root;
    while(slow != NULL){
        if(slow == fast) {
            cout<<"contain loop";
            current = fast;
            removeLoop(root, fast);
            break;
        };
        else{
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}

void print(Node* current){
    while(current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

int main(){
    Node* root = createNode(5);
    root->next = createNode(10);
    root->next->next = createNode(15);
    root->next->next->next = createNode(20);
    // root->next->next->next->next = createNode(30);
    root->next->next->next->next =root;
    detectLoop(root);
    print(root);
    return 0;
}