/*
Problem statement

You're given a positive integer represented in the form of a singly linked-list 
of digits. The length of the number is 'n'.



Add 1 to the number, i.e., increment the given number by one.



The digits are stored such that the most significant digit is at the head of 
the linked list and the least significant digit is at the tail of the linked list.



Example:
Input: Initial Linked List: 1 -> 5 -> 2

Output: Modified Linked List: 1 -> 5 -> 3

Explanation: Initially the number is 152. After incrementing it by 1, the number 
becomes 153.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3
1 5 2


Sample Output 1:
1 5 3


Explanation For Sample Input 1:
Initially the number is 152. After incrementing it by 1, the number becomes 153.


Sample Input 2:
2
9 9


Sample Output 2:
1 0 0


Explanation For Sample Input 2:
Initially the number is 9. After incrementing it by 1, the number becomes 100. 
Please note that there were 2 nodes in the initial linked list, but there are 
three nodes in the sum linked list.


Expected time complexity :
The expected time complexity is O('n').


Constraints:
1 <= 'n' <=  10^5
0 <= Node in linked list <= 9

There are no leading zeroes in the number.

Time Limit: 1 sec


*/

//Brute force: Using arrays
//T.C = O(3N)
//S.C = O(N)

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
vector<int> plusOne(vector<int>& digits) {

    int N = digits.size();
    int carry = 1;
    for(int i = N-1; i>=0 ; i--){
        int sum = carry+ digits[i];
        carry = sum/10;
        digits[i] = sum%10;
    }
    if(carry !=0){
        digits.insert(digits.begin(), carry);
    }
    return digits;
}

Node *addOne(Node *head)
{
    vector<int> digits;

    Node* temp = head;

    while(temp!=NULL){
        digits.push_back(temp->data);
        temp = temp->next;
    }

    vector<int> ans;
    ans = plusOne(digits);

    Node* dummy = new Node(-1);
    Node* mover = dummy;

    for(int i = 0; i<ans.size();i++){
        Node* newNode = new Node(ans[i]);
       
        mover->next = newNode;
        mover = newNode;

    }

    return dummy->next;
}

//another approach: using reversing the LL
//T.C = O(3N)
//S.C = O(1)

Node* reverse(Node* head){

    //Reverse the LL
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
Node *addOne(Node *head) {

    //T.C = O(3N)
    //S.C = O(1)
    
    head = reverse(head);
    Node *temp = head;
    int carry = 1;

    while (temp != NULL){

        temp->data = temp->data+carry;
        if(temp->data < 10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if(carry == 1){

        Node* newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);
    return head;
}


//In interview if they ask us to that we do not have to reverse the LL and do the operations in place
//This can be done using RECURSION and BACKTRACKING

//T.C = O(N)
//S.C = O(N) Recursive stack space

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
int helper(Node* temp){
    if(temp == NULL){
        return 1;
    }

    int carry = helper(temp->next);
    temp->data = temp->data+carry;
    if(temp->data < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}
Node *addOne(Node *head) {

    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}