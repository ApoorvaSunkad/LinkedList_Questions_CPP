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

Node* deleteHead(Node* head){
    //edge case
    if(head == nullptr){
        return head;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

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

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;


    head = deleteHead(head);
    printLL(head);

}

//Output:
//2 3 4
//After 1 is being deleted