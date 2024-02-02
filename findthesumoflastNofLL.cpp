/*
Given a single linked list of size N, calculate the sum of the last M nodes.

Example 1:

Input:
N = 6, M = 3
5 9 6 3 4 10
Output:
17
Explanation:
Sum of last three nodes in the linked list is 3 + 4 + 10 = 17.
Example 2:

Input:
N = 2,  M = 2
1 2
Output:
3
Explanation:
Sum of last two nodes in the linked list is 2 + 1 = 3.
Your Task:
You don't need to read input or print anything. Your task is to complete 
the function sumOfLastN_Nodes(), which takes two arguments as input, the reference 
pointer to the head of the linked list and the integer N. Return an Integer which 
is the sum of last M nodes.

Constraints:
1<=T<=100
1<=N<=M<=1000

*/

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

int sumOfLastN_Nodes(struct Node* head, int n)
{
    int sum = 0;
    Node* temp = head;
    int length = 0;

    // Calculate the length of the linked list
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Traverse to the (length - n)-th node
    // Reset temp to the beginning of the list
    temp = head;
    for (int i = 0; i < length - n; i++) {
        temp = temp->next;
    }

    // Sum the last n nodes
    for (int i = 0; i < n && temp != NULL; i++) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}