/*
Given a singly linked list of N nodes. Find the first node of the loop if 
the linked list has a loop. If a loop is present return the node data of the 
first node of the loop else return -1.

Example 1:

Input:

Output: 3
Explanation:
We can see that there exists a loop 
in the given linked list and the first
node of the loop is 3.
 

Example 2:

Input:

Output: -1
Explanation: No loop exists in the above
linked list.So the output is -1.

*/

#include<bits/stdc++.h>
using namespace std;

//Brute force
//T.C = O(N)
//S.C = O(N)

int findFirstNode(Node* head){

    map<Node*, int> visited;
    
    Node* temp = head;
    
    while (temp != NULL) {
        // Check if the node has already been visited
        if (visited.find(temp) != visited.end()) {
        // If yes, then it is the first node of the loop
            return temp->data;
        }

        // Mark the node as visited and increment the count
        visited[temp]++;

        // Move to the next node
        temp = temp->next;
    }

    // If no loop is found
    return -1;
}

//Optimised solution usig floyd's cycle detection method

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

Node* detectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    
    Node* fast = head;
    Node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

public:
//Function to find first node if the linked list has a loop.
int findFirstNode(Node* head){

    if(head == NULL){
        return NULL;
    }
    
    Node* intersection = detectLoop(head);
    
    if(intersection == NULL){
        return -1;
    }
    
    Node* slow = head;
    
    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow->data;
}