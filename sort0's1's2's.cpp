/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in 
the linked list as asked in the problem statement and returns the head of the 
modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 106

*/

//Brute force

//T.C = O(N)
//S.C = O(N)

Node* segregate(Node *head) {
        
    vector<int> v;

    Node* temp = head;

    while(temp!=NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }

    sort(v.begin(),v.end());
    int n = v.size();

    temp = head;

    int i = 0;

    while(temp!=NULL && i<n){
        temp->data = v[i];
        i++;
        temp = temp->next;
    }

    return head;   
}


//Another method

//T.C = O(2N)
//S.C = O(1)

Node* segregate(Node *head) {
    
    // Add code here
    Node* temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    
    while(temp!=NULL){
        if(temp->data == 0){
            cnt0++;
        }
        else if(temp->data == 1){
            cnt1++;
        }
        else{
            cnt2++;
        }
        temp = temp->next;
    }
    
    temp = head;
    
    while(temp!=NULL){
        if(cnt0){
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    
    return head;
    
}

//Optimised solution

//T.C = O(N)
//S.C = O(1)

Node* segregate(Node *head) {
        
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* temp = head;
    
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    
    while(temp!=NULL){
        
        if(temp->data == 0){
            
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    if (oneHead->next) {
        zero->next = oneHead->next;
    } else {
        zero->next = twoHead->next;
    }
    
    one->next = twoHead->next;
    two->next = NULL;
    
    Node* newHead = zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    
    return newHead;
}