//Creating a doubly linked list:
#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

    int data;
    Node* next;

    //Constructor
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
    //Destructor
    ~Node(){
        int value = this->data;
        if(this->next !=nullptr){
            delete next;
            next = nullptr;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d){
    //Assuming that the element is already present in the LL
    //Case 1: If LL is empty, means tail = NULL
    if(tail == nullptr){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //Non-empty list
        //Assuming that the element is already present in the LL
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }
        //When element is found ->curr is representing the element found
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    //If list is empty
    if(tail == nullptr){
        cout << "List is empty " << endl;
        return;
    }
    else{
        //Non-empty list
        //Assuming that the value is present in LL
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        //If LL has 1 node
        if(curr == prev){
            tail = nullptr;
        }
        //for more than >=2 nodes
        if(tail == curr){
            tail = prev;
        }
        curr->next = nullptr;
        free(curr);
    }

}
void PrintLL(Node* tail){
    Node* temp = tail;

    //empty LL
    if(tail == nullptr){
        cout << "List is empty " << endl;
        return;
    }

    do{
        cout << tail->data << " ";
        tail = tail->next; 
    }while(tail != temp);
    cout << endl;
}

int main(){
    Node* tail = nullptr;

    //Inserting in empty LL
    insertNode(tail,5,3);
    PrintLL(tail);

    // insertNode(tail,3,5);
    // PrintLL(tail);

    // insertNode(tail,5,7);
    // PrintLL(tail);

    // insertNode(tail,7,9);
    // PrintLL(tail);

    // insertNode(tail,3,4);
    // PrintLL(tail);

    // insertNode(tail,5,6);
    // PrintLL(tail);

    // insertNode(tail,9,10);
    // PrintLL(tail);

    // deleteNode(tail,10);
    // PrintLL(tail);

    deleteNode(tail,3);
    PrintLL(tail);
}



