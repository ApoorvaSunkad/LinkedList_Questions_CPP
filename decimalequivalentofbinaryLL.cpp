/*
Given a singly linked list of length n. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.
The significance of the bits decreases with the increasing index in the 
linked list.
An empty linked list is considered to represent the decimal value 0. 

Since the answer can be very large, answer modulo 109+7 should be printed.

Example 1:
Input:
n = 3
Linked List = {0, 1, 1}
Output:
3
Explanation:
0*22 + 1*21 + 1*20 =  1 + 2 + 0 = 3
Example 2:
Input:
n = 4
Linked List = {1, 1, 1, 0}
Output:
14
Explanation:
1*23 + 1*22 + 1*21 + 0*20 =  8 + 4 + 2 + 0 = 14
Your Task:
You do not have to take any input or print anything. Complete the function 
decimalValue() which takes a head node of a linked list as an input parameter 
and returns decimal representation of it.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


*/


#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

int lengthofLL(Node* head){
    int cnt = 0;
    
    Node* temp = head;
    
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    
    return cnt;
}
// Should return decimal equivalent modulo 1000000007 of binary linked list 
long long unsigned int decimalValue(Node *head)
{
    long long unsigned int ans = 0;
    
    int n = lengthofLL(head);
    
    Node* temp = head;
    
    for(int i = n-1; i>=0 && temp!=NULL; i--){
        ans = (ans * 2 + temp->data) % 1000000007;
        temp = temp->next;
    }
    return ans;
}