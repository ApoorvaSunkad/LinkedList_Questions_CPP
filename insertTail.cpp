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

void insertTail(Node* &tail, int d){
    Node* temp = new Node(d);

    if (tail == nullptr) {
        tail = temp;
    } 
    else{
        Node* curr = tail;
        while(curr->next!=nullptr){
           curr = curr->next;
        }
        curr->next = temp;
        temp->next = nullptr;
    }
}
int main(){
    //creating new node
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* tail = head;
    

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    printLL(head);
    insertTail(tail,6);
    insertTail(tail,7);
    printLL(head);

}

//Output:

/*

Before function call
1 2 3 4 
After function call
1 2 3 4 6 7 

*/