/*
Given two linked lists, your task is to complete the function makeUnion(), 
that returns the union list of two linked lists. This union list should include 
all the distinct elements only and it should be sorted in ascending order.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
Example 2:

Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the 
given two lists and returns the head of the new list.

Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)

*/


//Brute force
//T.C = O(N) to traverse each of LL and O(1) to put elements in set
//again to traverse the set and put in new LL is O(N)
//S.C = O(N)

/*
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

#include<bits/stdc++.h>
using namespace std;

struct Node* makeUnion(struct Node* head1, struct Node* head2){

    set<int> st;
    
    Node* temp1 = head1;
    
    while(temp1!=NULL){
        st.insert(temp1->data);
        temp1 = temp1->next;
    }
    
    Node* temp2 = head2;
    while(temp2!=NULL){
        st.insert(temp2->data);
        temp2 = temp2->next;
    }
    
    // Create a new linked list using elements from the set
    struct Node* resultHead = NULL;
    struct Node* resultTail = NULL;

    for (int num : st) {
    //   struct Node* newNode = new Node();
    //   newNode->data = num; these lines code is when we don't have constructor
    //called in class struct
    //   newNode->next = NULL;
        struct Node* newNode = new Node(num);

        if (resultHead == NULL) {
            resultHead = resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }

    return resultHead;
        
}