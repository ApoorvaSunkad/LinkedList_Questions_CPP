/*
You are given a pointer/ reference to the node which is to be deleted from the 
linked list of N nodes. The task is to delete the node. Pointer/ reference to 
head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be 
deleted is not a tail node in the linked list.

Example 1:

Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.
Example 2:

Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30
Explanation: After deleting 20 from
the linked list, we have remaining
nodes as 10, 4 and 30.
Your Task:
You only need to complete the function deleteNode that takes reference to the 
node that needs to be deleted. The printing is done automatically by the driver 
code.

Expected Time Complexity : O(1)
Expected Auxilliary Space : O(1)


*/


#include<bits/stdc++.h>
using namespace std;

//T.C = O(1)
//S.C = O(1)

void deleteNode(Node *del){

    if(del->next == NULL){
        return;
    }
    Node* prev = del;
    Node* curr = del->next;
    Node* forward = del->next->next;
    
    //copied the data
    prev->data = curr->data;
    
    prev->next = forward;
    delete curr;
       
}


//Leetcode question

/*
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to 
the first node of head.

All the values of the linked list are unique, and it is guaranteed that 
the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean 
removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node 
to be given node. node should not be the last node of the list and should 
be an actual node in the list.

We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.
 

Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list 
should become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list 
should become 4 -> 5 -> 9 after calling your function.
 

Constraints:

The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.

*/

//T.C = O(1)
//S.C = O(1)

void deleteNode(ListNode* node) {
    if(node->next == NULL){
        delete(node);
    }
    ListNode* delNode = node->next;
    node->val = delNode->val;
    node->next = delNode->next;
    delete(delNode);
}