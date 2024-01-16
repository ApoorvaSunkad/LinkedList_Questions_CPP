#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;

    //pointer to the next node in LL
    Node* next;

    //constructor is called with i/p parameters as data
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }

    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    free(temp->next->next);
    temp->next = nullptr;

    return head;
}
void printLL(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    Node* head = new Node(2);
    Node* second = new Node(5);
    Node* third = new Node(8);
    Node* fourth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    //printLL(head);
    head = deleteTail(head);
    printLL(head);

}
