/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109


*/

//Brute force : usig extra array

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(N)

ListNode* rotateRight(ListNode* head, int k) {

    vector<int>v;

    ListNode* temp = head;

    if(head == NULL){
        return NULL;
    }

    while(temp!=NULL){
        v.push_back(temp->val);
        temp = temp->next;
    }

    vector<int> ans;
    int n = v.size();
    int x = k % n;
    
    for(int i = n-x; i < n; i++)
    {
        ans.push_back(v[i]);
    }
    for(int i = 0; i < n-x; i++)
    {
        ans.push_back(v[i]);
    }  

    ListNode* dummy = new ListNode(-1);
    ListNode* mover = dummy;
    for(int i = 0; i<ans.size(); i++){
        ListNode* temp = new ListNode(ans[i]);
        mover->next = temp;
        mover = temp;
    }
    return dummy->next;
}


//Optimised solution

//T.C = O(N)
//S.C = O(1)

ListNode* findNthnode(ListNode* temp, int k){
    int cnt = 1;
    while(temp!=NULL){
        if(cnt==k) return temp;

        cnt++;
        temp = temp->next;
    }
    return temp;
}
public:
ListNode* rotateRight(ListNode* head, int k) {
    
    if(head == NULL || k==0){
        return head;
    }

    ListNode* tail = head;
    int len = 1;
    while(tail->next!=NULL){
        tail = tail->next;
        len++;
    }

    if(k%len == 0){
        return head;
    }

    k = k%len;

    //attach the tail to head
    tail->next = head;
    ListNode* newlastNode = findNthnode(head,len-k);

    head = newlastNode->next;
    newlastNode->next = NULL;

    return head;
}