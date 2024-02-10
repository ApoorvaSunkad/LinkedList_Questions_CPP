/*
Given the head of a linked list, return the list after sorting it in 
ascending order.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 
Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory 
(i.e. constant space)?

*/

//Brute force

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N) + O(NLOGN) + O(N)
//S.C = O(N)

ListNode* sortList(ListNode* head) {
    
    vector<int> v;

    ListNode* temp = head;

    while(temp!=NULL){
        v.push_back(temp->val);
        temp = temp->next;
    }

    sort(v.begin(),v.end());
    int n = v.size();

    temp = head;

    int i = 0;

    while(temp!=NULL && i<n){
        temp->val = v[i];
        i++;
        temp = temp->next;
    }

    return head;
}


//Using merge sort (which uses recursion)
//Without using extra space which previous algorithm was using.

#include<bits/stdc++.h>
using namespace std;

//Merging the first and second half
ListNode* merge2sortedLists(ListNode* leftHead, ListNode* rightHead){

    ListNode* temp1 = leftHead;
    ListNode* temp2 = rightHead;

    ListNode* dummyNode = new ListNode(-1);
    ListNode* curr = dummyNode;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val < temp2->val){
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

//Finding the middle of the LL to divide the LL into 2 halves
ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next; //(why head->next? bcz in case of even length LL
    // we need the first middle hence fast is pointing to head's next
    //It also works for odd length LL)

    while(fast == NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head) {

    //base case
    //empty list and if LL has only 1 node
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* middle = findMiddle(head);
    ListNode* rightHead = middle->next;
    middle->next = NULL;
    ListNode* leftHead = head;


    //Recursive call
    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return merge2sortedLists(leftHead,rightHead);
}

