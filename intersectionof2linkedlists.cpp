/*
Given two linked lists, the task is to complete the function findIntersection(), 
that returns the intersection of two linked lists. Each of the two linked list 
contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Your Task:
You task is to complete the function findIntersection() which takes the heads 
of the 2 input linked lists as parameter and returns the head of intersection 
list. Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those 
particular nodes appear in input list 1.

Constraints:
1 <= n,m <= 104

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)


*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(M+N)
//S.C = O(M+N)

Node* findIntersection(Node* head1, Node* head2){
    // code here
    // return the head of intersection list
    
    unordered_map<int,int> mp;
    
    Node* temp1 = head2;
    Node* temp2 = head1;
    
    // Create a new linked list using elements from the set
    Node* resultHead = new Node(-1);
    Node* resultTail = resultHead;
    
    while(temp1!=NULL){
        //int key = temp1->data;
        mp[temp1->data]++;
        temp1 = temp1->next;
    }
    
    while(temp2!=NULL){
        
        if (mp.find(temp2->data)!=mp.end()){
            
            Node* newNode = new Node(temp2->data);
            
            resultTail->next = newNode;
            resultTail = resultTail->next;
        }
        temp2 = temp2->next;
    }
    
    return resultHead->next;
}