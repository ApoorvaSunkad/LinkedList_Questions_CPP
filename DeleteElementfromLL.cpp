#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;

    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* convertarray2LL(vector<int> &Arr){ 
//we will be returning the pointer to the head that's why return type is Node*
    int n = Arr.size();
    Node* head = new Node(Arr[0]);
    Node* mover = head;
    for(int i = 1; i<n; i++){
        Node* temp = new Node(Arr[i]);
        mover->next = temp;
        mover = temp;
    }
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

Node* deleteEle(Node* head, int ele){
    //Edge case
    if(head == NULL){
        return head;
    }
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == ele){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main(){

    //Object created
    /* Node* node1 =  new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;*/

    vector<int> Arr = {2,5,8,7,3,1};
    Node* head = convertarray2LL(Arr);

    head = deleteEle(head,1);
    printLL(head);

}