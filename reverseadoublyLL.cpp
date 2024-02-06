/*
Given a doubly linked list of n elements. Your task is to reverse the doubly 
linked list in-place.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
Your Task:
Your task is to complete the given function reverseDLL(), which takes head 
reference as argument and this function should reverse the elements such that 
the tail becomes the new head and all pointers are pointing in the right order. 
You need to return the new head of the reversed list. 
The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 104
0 <= value of nodes <= 104


*/

//The brute force approach
//This is done using stacks which I will add later

//Optimal solution
//T.C = O(N)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

Node* reverseDLL(Node * head){
    
    //T.C = O(N)
    //S.C = O(1)
    
    if(head == NULL || head->next == NULL)
    return head;
    
    Node* before=NULL;
    Node* temp=head;
    Node* after=NULL;
    
    while(temp!=NULL){
        after=temp->next;
        temp->next=before;
        temp->prev=after;
        before=temp;
        temp=after;
    }
    return before;
    
}

//Watch striver's video for this solution
//Video Link: https://www.youtube.com/watch?v=u3WUW2qe6ww&t=637s