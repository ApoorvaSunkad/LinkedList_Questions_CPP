/*
You are given two sorted linked lists. You have to merge them to produce a 
combined sorted linked list. You need to return the head of the final linked list.

Note:

The given linked lists may or may not be null.
For example:

If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 
2 -> 3 -> 5 -> NULL

The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= L <= 10^5
1 ≤ data ≤ 10^6 and data != -1

Where L is the number of nodes in either of the two Linked List.

Time Limit: 1 sec 
Follow-up:

Try to solve this problem in linear time complexity and constant space complexity.

Sample Input 1:
7 8 -1
1 3 4 6 -1
Sample Output 1:
1 3 4 6 7 8 -1

Explanation of Input 1:
In this testcase, the first list is: 7 -> 8 -> NULL
The second list is: 1 -> 3 -> 4 -> 6 -> NULL
The final list would be: 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> NULL
Sample Input 2:
5 -1
1 3 6 10 -1
Sample Output 2
1 3 5 6 10 -1


*/

//Brute force approach: striver

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N1) + O(N2) + O(NLOGN) + O(N)(To insert values of vector in LL)
//S.C = O(N) + O(N)

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    vector<int> v;

    Node<int>* temp1 = first;
    Node<int>* temp2 = second;

    while(temp1!=NULL){
        v.push_back(temp1->data);
        temp1 = temp1->next;
    }

    while(temp2!=NULL){
        v.push_back(temp2->data);
        temp2 = temp2->next;
    }

    int n = v.size();

    sort(v.begin(),v.end());

    Node<int>* resultHead = NULL;
    Node<int>* resultTail = NULL;

    for(int i = 0; i<n; i++){
        Node<int>* newNode = new Node<int>(v[i]);

        if (resultHead == NULL) {
            resultHead = resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }
    return resultHead;
}


//Optimised solution

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N1+N2)
//S.C = O(1)
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    
    Node<int>* temp1 = first;
    Node<int>* temp2 = second;

    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* curr = dummyNode;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data < temp2->data){
            curr->next = temp1;
            curr = temp1;
            temp1 = temp1->next;
        }
        else{
            curr->next = temp2;
            curr = temp2;
            temp2 = temp2->next;
        }
    }

    if(temp1!=NULL){
        curr->next = temp1;
    }
    else{
        curr->next = temp2;
    }

    return dummyNode->next;
}