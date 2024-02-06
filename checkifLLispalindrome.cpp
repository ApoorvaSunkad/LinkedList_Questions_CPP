/*
Given a singly linked list of size N of integers. The task is to check if the 
given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as 
reference as the only parameter and returns true or false if linked list is 
palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive 
stack space as well)


*/

//Brute force: My solution
//But did not pass all test cases

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N) + O(N) to traverse LL again
//S.C = O(1)

Node* reverseList(Node *head){

    //If list is empty or has only single node in LL
    if(head == NULL || head->next == NULL){
        return head;
    }

Node* prev = NULL;
Node* curr = head;

    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
    public:
//Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    Node* head2 = reverseList(head);
    
    Node* temp = head;
    
    Node* temp1 = head2;
    
    while(temp!=NULL && temp1!=NULL){
        if(temp->data != temp1->data){
            return false;
        }
        temp =  temp->next;
        temp1 = temp1->next;
    }
    return true;
}


//Another brute force approach this approach is good but has more space comp.
//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;
 
bool isPalin(vector<int>& arr){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<= e){
        if(arr[s] != arr[e]) return false; 
        s++;
        e--;
    }
    return true;
}
//Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    //Your code here
    vector<int> arr; 
    Node* ptr = head;
    while(ptr != NULL){
        arr.push_back(ptr->data);
        ptr = ptr->next;
    }
    return isPalin(arr);
}


//Using fast and slow pointers and finding the middle of LL
//and then reversing the LL from middle till last node and then
//checking if the reversed part is equal to initial part

#include<bits/stdc++.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

bool isPalindrome(Node *head){
    
    //If LL has a single node then it will be palindrome
    if(head->next == NULL){
        return true;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //Reverse the second half of the LL
    //Slow will be pointing to middle of LL
    Node* curr = slow;
    Node* prev = NULL;
    Node* forward = NULL;
    
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    //Comparing 2 halves
    Node* head2 = prev;
    while(head2!=NULL){
        if(head->data != head2->data){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
