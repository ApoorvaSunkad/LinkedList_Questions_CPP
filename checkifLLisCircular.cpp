/*
Given head, the head of a singly linked list, find if the linked list is circular 
or not. A linked list is called circular if it not NULL terminated and all nodes 
are connected in the form of a cycle. An empty linked list is considered as circular.

Note: The linked list does not contains any inner loop.

Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 0
Your Task:
The task is to complete the function isCircular() which checks if the given 
linked list is circular or not. It should return true or false accordingly. 
(the driver code prints 1 if the returned values is true, otherwise 0)

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <=Number of nodes<= 100

*/

//Brute force: 
//T.C = O(N)
//S.C = O(1)

bool isCircular(Node *head)
{
   // Your code here
   Node* temp = head;
   
   if (head == nullptr)
    {
        return false; 
    }
   
   while(temp!=NULL && temp->next!=NULL){
       if(temp->next==head){
           return 1;
       }
       temp = temp->next;
   }
   return 0;
}

//Using slow and fast pointers
//T.C =
//S.C =

#include<bits/stdc++.h>
using namespace std;

bool isCircular(Node *head)
{
    if(head == nullptr) {
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}