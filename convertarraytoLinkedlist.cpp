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
int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head , int val){
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){

    vector<int> Arr = {2,5,8,7};
    Node* head = convertarray2LL(Arr);
    //cout << lengthofLL(head) << endl;

    //Printing Head of a LL
    //cout << head->data << endl;

    //Traversing a LL
    /*Node* temp = head;

    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }*/

    cout << checkIfPresent(head, 51);
}