/*
Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only 
argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/

//Brute force code: Using stack
//T.C = O(2N)
//S.C = O(N), N = no. of nodes

#include<bits/stdc++.h>
using namespace std;

ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        stack<int> st;

        ListNode* temp = head;

        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(!st.empty() && temp!=NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}
//T.C = O(N)
//S.C = O(1)

struct Node* reverseList(struct Node *head){

    //If list is empty or has only single node in LL
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

//RECURSIVE CODE

#include<bits/stdc++.h>
using namespace std;
//T.C = O(N)  Where N is no. of nodes in the list
//S.C = O(N) because of stack space

void reverseLL(Node* &head, Node* curr, Node* prev){
    //Base case
    if(curr == NULL){
        head = prev;
        return;
    }
    
    Node* forward = curr->next;
    
    //Recursive call
    reverseLL(head,forward,curr);
    curr->next = prev;
}
//Function to reverse a linked list.
struct Node* reverseList(struct Node *head){

    Node* curr = head;
    Node* prev = NULL;
    reverseLL(head,curr,prev);
    return head;
    
}