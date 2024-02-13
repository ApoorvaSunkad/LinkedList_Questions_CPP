/*
Given a singly linked list, remove all the nodes in the list which have any 
node on their right whose value is greater. (Not just immediate Right , 
but entire List on the Right)

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last
node has a greater value node on its right,
so all the nodes except the last node must
be removed.
Your Task:
The task is to complete the function compute() which should modify the list as 
required and return the head of the modified linked list. 
The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 105
1 ≤ element of linked list ≤ 105

Note: Try to solve the problem without using any extra space.

*/

//My brute force approach

//T.C = O(N^2) 
//S.C = O(N)

Node *compute(Node *head)
{
    vector<int> v;
    
    Node* temp = head;
    
    while(temp!=NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }
    
    int n = v.size();
    
    vector<int> ans;
    
    int leader=v[n-1];
    
    ans.push_back(leader);
    
    for(int i=n-2;i>=0;i--){
        if(v[i]>=leader){
            ans.push_back(v[i]);
            leader=v[i];
        } 
    }
    reverse(ans.begin(),ans.end());
    
    Node* dummy = new Node(-1);
    Node* mover = dummy;
    for(int i = 0; i<ans.size(); i++){
        Node* temp = new Node(ans[i]);
        mover->next = temp;
        mover = temp;
    }
    return dummy->next;
}


//Optimised solution
//T.C = O(N)
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
Node *compute(Node *head)
{
    head = reverseList(head);
    
    int maxVal = head->data;
    
    Node* curr = head->next;
    Node* prev = head;
    
    while(curr!=NULL){
        if(curr->data >= maxVal){
            prev = curr;
            maxVal = curr->data;
        }
        else{
            prev->next = curr->next;
        }
        curr = curr->next;
    }
    
    head = reverseList(head);
    return head;
        
}
    