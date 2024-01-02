#include<bits/stdc++.h>
using namespace std;

//Node of a singly linked list
class Node{

    public:

    int data;

    // Pointer to next node in LL
    Node* next;


   //constructor is called with input parameter as data

   Node(int data){

    this->data = data;
    this->next = NULL;

    // It's a special pointer available in C++ that points to the object for which the member function is called.

    /*
    data: This is the parameter passed to the constructor. It's a local variable within the constructor, holding 
    the value that was provided when creating an instance of the class.

    this->data: This refers to the member variable data of the current object (the object being constructed). 
    The this pointer is used to differentiate between the local variable data and the member variable data.

    = data: This is the assignment operator. It assigns the value of the local variable data (the one passed as 
    a parameter) to the member variable data of the current object.
    
    */

   }
};

int main(){
    //creating an object of Node

    Node* node1  =  new Node(5); // why * and new keyword is used because we are creating this
    // linked list dynamically in "Heap Memory".

    // This above line is similar to int* i = new int;
    // or ex: int* arr =  new int[5]; (Node is custom data type which means a class)
    // new Node() -> this () brackets indicates that we can put values inside it similar to arrays.
    
    cout << node1->data << endl;
    cout << node1->next << endl;

}