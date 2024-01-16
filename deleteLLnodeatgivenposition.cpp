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

Node* deleteatKthnode(Node* head,int k){
  //if LL is empty
  if(head==nullptr){
    return head;
  }

  if(k==1){
    Node* temp = head;
    while(temp!=nullptr){
        head = head->next;
        free(temp);

        return head;
    }
  }

  Node* temp = head;
  Node* prev = nullptr;
  int cnt  = 0;

  while(temp!=nullptr){
    cnt++;
    if(cnt==k){
        prev->next = prev->next->next;
        free(temp);
        break;
    }
    prev = temp;
    temp = temp->next;
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

int main(){

    Node* head = new Node(2);
    Node* second = new Node(5);
    Node* third = new Node(8);
    Node* fourth = new Node(10);
    Node* fifth = new Node(17);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    //printLL(head);
    head = deleteatKthnode(head,3);
    printLL(head);

}
