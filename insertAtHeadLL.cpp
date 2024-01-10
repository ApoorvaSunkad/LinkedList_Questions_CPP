//This is by love babbar

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;

    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void printLL(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    //creating a new node
    Node* node1 = new Node(10);

    Node* head = node1;
    printLL(head);

    insertatHead(head,12);

    printLL(head);

    insertatHead(head,15);

    printLL(head);
}
