/*
Given a singly linked list and a number k, you are required to complete the 
function modularNode() which returns the modular node of the linked list.
A modular node is the last node of the linked list whose Index is divisible 
by the number k, i.e. i%k==0.
Note: If no such node is available, return -1. We are following 1 indexing.

Example 1:

Input: LinkedList: 1->2->3->4->5->6->7
       k = 3
Output: 6
Explanation: Indexing of the linked list is
same as the values of the Node. The maximum
index is which is divisble by 3 is 6 and the
node value of the 6th index is 6.
Example 2:

Input: LinkedList: 19->28->37->46->55
           k = 2
Output: 46
Explanation: Index start from 1 and end at 5.
The maximum Index which is divisble by 2 is 4
and 4th Node in the list is 46.
 

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

int modularNode(Node* head, int k)
{
	Node* temp = head;
	
	int maxi = -1;
	
	int cnt = 0;
	while(temp!=NULL){
	    cnt++;
	    
	    if(cnt%k == 0){
	        int ans = cnt;
	        maxi = max(ans,maxi);
	    }
	    temp = temp->next;
	}
	if (maxi == -1) {
        return -1;
    }
	// Reset temp to the beginning of the list
    temp = head;

    // Traverse the list till maxi
    for (int i = 1; i < maxi && temp != NULL; i++) {
        temp = temp->next;
    }

    return temp->data;
}