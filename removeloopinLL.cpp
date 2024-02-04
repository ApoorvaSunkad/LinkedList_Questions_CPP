/*
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node 
at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last 
node which is forming the loop.


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 

Example 2:

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 

Example 3:

Input:
N = 4
value[] = {1,2,3,4}
X = 1
Output: 1
Explanation: The link list looks like 
1 -> 2 -> 3 -> 4
^              |
|______________|
A loop is present. 
If you remove it successfully, 
the answer will be 1. 


*/

#include<bits/stdc++.h>
using namespace std;
//T.C = O(N)
//S.C = O(1)

Node* detectLoop(Node* head){

    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    
        if(fast==slow){
            return slow;
        }
    }
    return NULL;        
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    
    Node* intersection = detectLoop(head);
    
    // Check if there is no loop
    if(intersection == NULL) {
        return NULL;
    }
    
    //To traverse the LL
    Node* slow = head;
    
    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow; 
    //or can return "intersection" both point at same node(i.e starting node)
}
public:
//Function to remove a loop in the linked list.
void removeLoop(Node* head){
    // just remove the loop without losing any nodes
    
    
    //This code will work even if there is a single node in LL
    if(head == NULL){
        return;
    }
    
    Node* startofLoop = getStartingNode(head);
    
    if (startofLoop == NULL) {
        return;
    }
    
    Node* temp = startofLoop;
    
    while(temp->next != startofLoop){
        temp = temp->next;
    }
    
    temp->next = NULL;
}