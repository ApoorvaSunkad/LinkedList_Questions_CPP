/*
Given two decimal numbers represented by two linked lists of size N and M 
respectively. The task is to return a linked list that represents the sum of 
these two numbers.

For example, the number 190 will be represented by the linked list, 
1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers 
is 190 + 25 = 215, which will be represented by 2->1->5->null. 
You are required to return the head of the linked list 2->1->5->null.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of 
both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000

*/

Node* reverse(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr!=NULL){
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
//Function to add two numbers represented by linked list.
struct Node* addTwoLists(struct Node* first, struct Node* second){
        // code here
    first = reverse(first);
    second = reverse(second);
    
    Node* temp1 = first;
    Node* temp2 = second;
    
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    int carry = 0;
    
    while(temp1!=NULL || temp2!=NULL){
        int sum = carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;
        
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        
        curr->next = newNode;
        curr = curr->next;
        
        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    dummyHead = dummyHead->next;
    dummyHead = reverse(dummyHead);
    
    return dummyHead;
}