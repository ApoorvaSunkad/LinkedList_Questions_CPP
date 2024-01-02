#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;

    // Pointer to next node in LL
    Node* next;

   //constructor is called with input parameter as data

    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

Node* convertarray2LL(vector<int> &Arr){ 
//we will be returning the pointer to the head that's why return type is Node*
    Node* head = new Node(Arr[0]);
    Node* mover = head;
    for(int i = 1; i<Arr.size(); i++){
        Node* temp = new Node(Arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

int main(){

    vector<int> Arr = {2,5,8,7};
    Node* head = convertarray2LL(Arr);
    cout << head->data << endl;
}