#include<bits/stdc++.h>
using namespace std;

//More info: https://www.scaler.com/topics/doubly-linked-list-cpp/

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

void deleteHead(Node* &head){
    Node* temp = head;

    temp->next->prev = nullptr;
    head = temp->next;
    temp->next = nullptr;
    free(temp); //Dynamically allocated temp in heap memory hence we need to maunually delete.
}

void deleteTail(Node* &head){
    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next->prev = nullptr;
    temp->next = nullptr;
    free(temp->next);
}

void deletekthNode(Node* head, int k){

    if(k==1){
        //Means deleting head
        Node* temp = head;

        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        free(temp);
    }else{
        Node* temp = head;
        Node* prev = nullptr;
        int cnt = 1;

        while(cnt<k){
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        temp->prev = nullptr;
        prev->next = temp->next;
        temp->next = nullptr;
        free(temp);
    }
}


int main(){
    //We will create a doubly LL of 3 nodes

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node1->prev = nullptr;

    node2->next = node3;
    node2->prev = node1;

    node3->next = node4;
    node3->prev = node2;

    node4->next = node5;
    node4->prev = node3;

    node5->next = nullptr;
    node5->prev = node4;

    printLL(node1);

    //deleteHead(node1);
    //printLL(node1);

    //deleteTail(node1);
    //printLL(node1);

    deletekthNode(node1, 5);
    printLL(node1);


}