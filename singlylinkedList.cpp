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

    //why constructor is written here?
    
    /* In this code, the constructor is used to initialize the data members of the Node class when a new object 
    of the class is created. The constructor is crucial for several reasons:

    Initialization: The constructor ensures that the newly created object starts with a valid and consistent state. 
    In the case of the Node class, the constructor initializes the data member with the provided value and sets 
    the next pointer to NULL. This ensures that a new node is properly initialized for inclusion in a linked list.

    Encapsulation: The constructor encapsulates the initialization logic within the class. It hides the details 
    of how the object is initialized from the external code. This promotes better code organization and reduces 
    the chance of errors related to uninitialized variables.

    Ease of Use: Using a constructor makes it simpler and more convenient to create objects. Without a constructor, 
    you would need to manually initialize each object after creation, which could lead to errors and is less readable.

    While it is technically possible to create objects without a constructor and then manually set the values of 
    the data members, using a constructor is a best practice for ensuring that objects are consistently initialized. 
    It helps in writing cleaner, more maintainable, and less error-prone code.
    
    */

};

int main(){

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;


    Node* temp = head;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}