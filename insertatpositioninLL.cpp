///BY love Babbar

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

void insertatTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertatPos(Node* &head, int pos, int d){
    Node* temp = head;
    int cnt = 1;
    while(cnt<pos-1){
        temp =  temp->next;
        cnt++;
    }
    //creating a node for d
    Node* nodetoInsert = new Node(d);

    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
    
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
    Node* tail = node1;

    printLL(head);

    insertatTail(tail,12);
    printLL(head);

    insertatTail(tail,15);

    printLL(head);

    insertatPos(head,3,28);
    printLL(head);

    insertatPos(head,4,29);
    printLL(head);
}
