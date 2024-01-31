/*
Given two Singly Linked List of N and M nodes respectively. The task is to check 
whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.

Example 1:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: Not identical 
Example 2:

Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: Identical
 
Your Task:
The task is to complete the function areIdentical() which takes the head of both 
linked lists as arguments and returns True or False.

Constraints:
1 <= N <= 103

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(min(M, N))
/*
Here, M and N are the sizes of the two linked lists and we have to traverse them till 
any one of them becomes NULL . 
So our time complexity will be a minimum of the size of two linked lists.
*/
//S.C = O(1)

bool areIdentical(struct Node *head1, struct Node *head2)
{
    // Code here
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 != NULL || temp2 != NULL)
    {
        return false;  // Not identical
    }

    return true;  // Identical
}

//Using Recursion

bool areIdentical(struct Node *head1, struct Node *head2)
{
    if(head1 == nullptr && head2 == nullptr){
        return true;
    }
    
    if((head1 == nullptr || head2 == nullptr)){
        return false;
    }
    
    if(head1->data != head2->data){
        return false;
    }
    
    return isIdentical(head1->next, head2->next);
}