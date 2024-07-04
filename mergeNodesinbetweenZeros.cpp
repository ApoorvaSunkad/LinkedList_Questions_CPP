/*
You are given the head of a linked list, which contains a series of 
integers separated by 0's. The beginning and end of the linked list will 
have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them 
into a single node whose value is the sum of all the merged nodes. 
The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list 
contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
 

Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
The beginning and end of the linked list have Node.val == 0.

*/

#include<iostream>
#include<stack>
using namespace std;

//T.C = O(2N)
//S.C = O(N)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
}
ListNode* mergeNodes(ListNode* head) {
       stack<int> st;

        ListNode* temp = head;

        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        int sum = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* mover = dummy;

        while(!st.empty()){
            if(st.top()==0){
                st.pop();
            }
            else{
                sum+=st.top();
                st.pop();
                if(st.top()==0){
                    ListNode* newNode = new ListNode(sum);
                    mover->next = newNode;
                    mover = newNode;
                    st.pop();
                    sum = 0;
                }
            }
        }
        return reverseLL(dummy->next);
}

//Optimized approach

ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next; // Start from the node after the initial 0
        ListNode* nextSum = modify;

        while (nextSum != nullptr) {
            int sum = 0;
            // Find the sum of all nodes until you encounter a 0.
            while (nextSum->val != 0) {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }

            // Assign the sum to the current node's value.
            modify->val = sum;
            // Move nextSum to the first non-zero value of the next block.
            nextSum = nextSum->next;
            // Move modify also to this node.
            modify->next = nextSum;
            modify = modify->next;
        }
        return head->next; // Skip the initial 0 node.
}