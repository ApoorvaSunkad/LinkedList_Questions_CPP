/*
You are given the head of a singly linked-list. The list can be 
represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes 
themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

*/

//Brute force
//T.C = O(3N)
//S.C = O(2N)

#include<bits/stdc++.h>
using namespace std;

void reorderList(ListNode* head) {
        ListNode* temp = head;

        vector<int> v1;
        vector<int> v2;

        while(temp!=NULL){
            v1.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0, j = v1.size()-1;
        while(i<=j){
            v2.push_back(v1[i]);
            v2.push_back(v1[j]);
            i++;
            j--;
        }

        temp = head;
        int k = 0;
        while(temp!=NULL && k < v2.size()){
            temp->val = v2[k];
            k++;
            temp = temp->next;
        }
}

//Optimised approach: This involves the concept of finding the middle
//node using hare and tortoise method and using the concept of reversing
//the linked list and using the concept of palindrome linked list


//Code
//T.C = O(N)
//S.C = O(1)

void reorderList(ListNode* head) {

    if(head == NULL || head->next == NULL){
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* curr = slow;
    ListNode* prev = NULL;

    while(curr!=NULL){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    ListNode* head1 = head;
    ListNode* head2 = prev;

    while(head2->next != NULL){
        ListNode* temp1 = head1->next;
        head1->next = head2;
        head1 = temp1;

        ListNode* temp2 = head2->next;
        head2->next = head1;
        head2 = temp2;
    }

}