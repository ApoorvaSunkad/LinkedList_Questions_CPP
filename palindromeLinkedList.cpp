/*
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:

Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?


*/

//Brute force: extreme naive solution which I could think of is using array data
//structure

//T.C = O(2N)
//S.C = O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    bool checkPalin(vector<int>arr){
        int start = 0,end = arr.size()-1;

        while(start<=end){
            if(arr[start] != arr[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;

        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        bool check = checkPalin(v);

        if(check == false){
            return false;
        }

        return true;
    }
};


//2nd brute force solution: Using stacks (same T.C and S.C)
//T.C = O(2N)
//S.C = O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        stack<int> st;
        ListNode* temp = head;

        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp!=NULL && !st.empty()){
            if(temp->val != st.top()){
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};


//Optimised solution : from striver
//T.C = O(2N) - Please watch striver bhaiya's video for T.C
//S.C = O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){

        //Reverse the LL
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {

        //Edge case
        if(head == NULL || head->next == NULL){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        //fast->next!=NULL is for odd length LL
        //fast->next->next!=NULL is for even length LL
        //For finding the middle of LL
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reversing the second half of the LL
        ListNode* newHead = reverse(slow->next);

        //Taking the help of 2 pointers
        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=NULL){
            if(first->val != second->val){
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);
        return true;
    }
};