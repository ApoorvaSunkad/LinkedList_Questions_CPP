/*
Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle 
element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of 
the list is 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.
Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 
Explanation: 
Middle of linked list is 7.

*/

#include<bits/stdc++.h>
using namespace std;
/*
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/


//This is the brute force approach
//T.C = O(N)for finding length of LL + O(N/2) for traversing half of LL
//S.C = O(1)

int getLength(Node* head){
    int cnt = 0;
    
    while(head!=NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
public:
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    int len = getLength(head);
    int ans = (len/2);
    
    Node* temp = head;
    int cnt = 0;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }
    return temp->data;
}


//Optimised approach 
//Using the concept of slow and fast pointers(Hare and tortoise Algorithm)

#include<bits/stdc++.h>
using namespace std;

/*
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

int getMiddle(Node *head){
    // Your code here
    Node* fast = head;
    Node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL){
        //fast->next !=NULL is when the LL has odd no. of nodes
        //fast!=NULL is when the LL has even no. of nodes
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}