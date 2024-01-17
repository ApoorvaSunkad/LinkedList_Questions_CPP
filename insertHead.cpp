#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;

    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void printLL(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
int main(){
    //creating new node
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    printLL(head);
    insertHead(head,6);
    printLL(head);

}