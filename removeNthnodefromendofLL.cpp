/*
Given the head of a linked list, remove the nth node from the end of the list 
and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

*/

//Brute force:
//T.C = O(len) + O(Len-n) => O(2*len)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    ListNode* temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == n) {
        ListNode* newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - n;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL) {
        res--;
        if (res == 0) {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}


//Optimised approach

//T.C = O(Len)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* fast = head;
    ListNode* slow = head;
    
    for(int i = 0; i<n; i++){
        fast = fast->next;
    }

    if(fast == NULL){
        return head->next;
    }

    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);
    return head;
}




//Another variation of this problem


/*
Given a linked list consisting of L nodes and given a number N. The task is to 
find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.  
Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of nodes in the
linked list, the output is -1.
Your Task:
The task is to complete the function getNthFromLast() which takes two arguments:
reference to head and N and you need to return Nth from the end or -1 in case 
node doesn't exist.

Note:
Try to solve in a single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= L <= 106
1 <= N <= 106


*/


//Optimised solution

#include<bits/stdc++.h>
using namespace std;

//T.C = O(Len)
//S.C = O(1)

int getNthFromLast(Node *head, int n){

    // Your code here
    if(head == NULL){
        return -1;
    }
    int i = 0;
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && i<n){
        fast = fast->next;
        i++;
    }
    
    if(fast == NULL){
        if(i<n){
            return -1;
        }
        return slow->data;
    }
    
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow->next->data;
}