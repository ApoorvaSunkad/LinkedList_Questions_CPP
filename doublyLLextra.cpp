/*
Here I have not created any node in main function instead I have pointed head and tail 
to NULL

*/

//Creating a doubly linked list:
#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


//Gives the length of doubly LL
int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=nullptr){
        len++;
        temp = temp->next;
    }
    return len;
}

//Prints the doubly LL
void printLL(Node* head){
    Node* temp = head;

    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head,Node* &tail, int data){
    //Node* temp = new Node(data);

    //If doubly LL is empty
    if(head == nullptr){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head,int data){
    //If LL is empty

    if(tail == nullptr){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head, int pos, int data){
    //If position is 1
    if(pos == 1){
        insertAtHead(head,tail,data);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == nullptr){
        insertAtTail(tail,head,data);
        return;
    }

    Node* nodetoInsert = new Node(data);

    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;
    temp->next = nodetoInsert;
    temp->prev = nodetoInsert;

}

int main(){
    //Node* node1 = new Node(10);
    Node* head = nullptr;
    Node* tail = nullptr;

    printLL(head);
    //int n = getLength(head);
    cout << getLength(head) << endl;

    //Inserting node at head(beginning)
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    
    printLL(head);

    cout << getLength(head) << endl;

    insertAtTail(tail,head,70);
    insertAtTail(tail,head,25);
    printLL(head);

    insertAtPosition(tail,head,3,100);
    insertAtPosition(tail,head,9,200); //end of doubly LL
    insertAtPosition(tail,head,1,5); //At the start of doubly LL
    printLL(head);
}