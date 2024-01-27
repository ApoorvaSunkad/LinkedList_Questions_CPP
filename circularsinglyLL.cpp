#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = nullptr; 
    }
};

void printLL(Node* head){
    Node* temp = head;

    // If linked list is not empty
    if(head == nullptr){
        cout << "List is empty " << endl;
        return;
    }
    
    do{
        cout << head->data << " ";
        head = head->next; 
    }while(head != temp);
    cout << endl;
}

void insertHead(Node* &tail, int d){
    Node* temp = new Node(d);

    //Case 1: If LL is empty, means tail = NULL
    if(tail == nullptr){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //Non-empty list
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}

void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);

    //Case 1: If LL is empty, means tail = NULL
    if(tail == nullptr){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //Non-empty list
        temp->next = tail->next;
        tail->next = temp;
        tail = tail->next;
    }
}
int main(){

    //If LL has no node
    //Node* one = nullptr;

    Node* one = new Node(1);
    Node* tail = one;
    // Node* two = new Node(2);
    // Node* three = new Node(3);
    // Node* four = new Node(4);
    // Node* five = new Node(5);
    // Node* tail = one;

    // //Connect them
    // one->next = two;
    // two->next = three;
    // three->next = four;
    // four->next = five;
    // five->next = one;

    printLL(tail);
    insertHead(tail,2);
    printLL(tail);

}