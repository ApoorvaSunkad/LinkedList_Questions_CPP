/*
Given a singly linked list and a number k. Write a function to find the 
(N/k)th element, where N is the number of elements in the list. We need to 
consider ceil value in case of decimals.

Input:
The first line of input contains an integer T denoting the number of test cases. 
The first line of each test case consists of an integer N. The second line consists 
of N spaced integers.The last line consists of an integer k.

Output:
return the data value of (N/k)th node in the Linked List.

User Task:
The task is to complete the function fractional_node() which should find the n/kth 
node in the linked list and return its data value.

Constraints: 
1 <= T <= 100
1 <= N <= 100
K > 0

Example:
Input:
2
6
1 2 3 4 5 6
2
5
2 7 9 3 5
3

Output:
3
7

Explanation:
Testcase 1: 6/2th element is the 3rd(1-based indexing) element which is 3.

Testcase 2: 5/3rd element is the 2nd element as mentioned in question that 
we need to consider ceil value in case of decimals. So 2nd element is 7.


*/

#include<bits/stdc++.h>
using namespace std;
//T.C = O(N)
//S.C = O(1)

int fractional_node(struct Node *head, int k)
{
    // your code here
    Node* temp = head;
    int cnt = 0;
    
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    
    int position = ceil((double)cnt / k);

    // Reset temp to the beginning of the list
    temp = head;

    // Traverse the list to the (N/k)th node
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // Return the data value of the (N/k)th node
    return temp->data;
}