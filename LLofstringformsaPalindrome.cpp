/*
Given a linked list with string data, check whether the combined string formed is palindrome. 
If the combined string is palindrome then return true otherwise return false.

Example:

Input:

Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.
Input:

Output : false
Explanation: As string "abcdba" is not palindrome the function should return false.
Expected Time Complexity:  O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Node.data.length<= 103
1<=list.length<=103

*/
#include<iostream>
using namespace std;

struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

bool reverse(string str){
        
    int n = str.length();
    int start = 0, end = n-1;
    while(start<=end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
        
}

bool compute(Node* head) {
       
    Node* temp = head;
    string ans = "";
    
    if(temp == NULL){
        return false;
    }
    
    while(temp!=NULL){
        ans+=temp->data;
        temp = temp->next;
    }
    
    bool final = reverse(ans);
    if(final == true){
        return true;
    }
    
    return false;
}