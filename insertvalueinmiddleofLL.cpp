/*
Given a linked list of size N and a key. The task is to insert the key in 
the middle of the linked list.

Example 1:

Input:
LinkedList = 1->2->4
key = 3
Output: 1 2 3 4
Explanation: The new element is inserted
after the current middle element in the
linked list.
Example 2:

Input:
LinkedList = 10->20->40->50
key = 30
Output: 10 20 30 40 50
Explanation: The new element is inserted
after the current middle element in the
linked list and Hence, the output is
10 20 30 40 50.
 

Your Task:
The task is to complete the function insertInMiddle() which takes head reference 
and element to be inserted as the arguments. The printing is done automatically by 
the driver code.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)


*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

Node* getMiddle(Node *head){
    // Your code here
    Node* fast = head->next;
    Node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL){
        //fast->next !=NULL is when the LL has odd no. of nodes
        //fast!=NULL is when the LL has even no. of nodes
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	Node* middleNode = getMiddle(head);
    
    Node* nodetoInsert = new Node(x);
    
    nodetoInsert->next = middleNode->next;
    middleNode->next = nodetoInsert;
    
    return head;
	
}