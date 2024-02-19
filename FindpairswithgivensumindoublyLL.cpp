/*
Problem statement
A doubly-linked list is a data structure that consists of sequentially 
linked nodes, and the nodes have reference to both the previous and the 
next nodes in the sequence of nodes.



You are given a sorted doubly linked list of size 'n', consisting of 
distinct positive integers, and a number 'k'.



Find out all the pairs in the doubly linked list with sum equal to 'k'.



Example :
Input: Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5

Output: (1, 4) and (2, 3)

Explanation: There are 2 pairs in the linked list having sum 'k' = 5.
Detailed explanation ( Input/output format, Notes, Images )
Sample input 1:
5
1 2 3 4 9
5


Sample output 1
2
1 4
2 3


Explanation for sample input 1 :
There are 2 pairs in the linked list having sum equal to 'k' (= 5).


Sample input 2:
5
1 10 11 12 27
7


Sample output 2:
0


Explanation for sample output 2
There is no pair in the linked list with sum equal to 'k' (= 7).


Expected time complexity :
The expected time complexity is O('n').


Constraints:
2 <= 'n' <= 10 ^ 4
1 <= 'data' in any node <= 10 ^ 4
1 <= 'k' <= 10 ^ 4

'data' in every node is distinct.

Time limit: 1 second

*/

//Brute force: which I thought
//T.C = O(N^2)
//S.C = O(1)

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int, int>> v;

    pair<int, int>p;
    vector<int> ans;

    Node* temp = head;

    while(temp!=NULL){
        ans.push_back(temp->data);
        temp =  temp->next;
    }

    for(int i = 0; i<ans.size();i++){
        for(int j = i+1; j<ans.size(); j++){
            if(ans[i]+ans[j]==k){
                p.first = ans[i];
                p.second = ans[j];
                v.push_back(p);
            }
        }
    }
    
    return v;
}


//2nd brute force: Which I thought

//T.C = O(N^2)
//S.C = O(1) Depends upon pairs

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int, int>> v;

    if (head == nullptr || head->next == nullptr) {
        // If the list has less than two nodes, return empty vector
        return v;
    }

    Node* temp = head;

    while (temp != nullptr) {
        Node* temp1 = temp->next;

        while (temp1 != nullptr && temp->data + temp1->data <= k) {
            if ((temp->data + temp1->data) == k) {
                v.push_back({temp->data, temp1->data});
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }

    return v;
}

//Optimised solution: Using two pointers why because the doubly LL
//has prev pointer and can move backwards as compared to singly LL


//T.C = O(N)
//S.C = O(1) depends upon pairs

Node* findTail(Node* head){
    Node* tail = head;

    while(tail->next !=NULL){
        tail = tail->next;
    }
    return tail;
}
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> ans;
    if(head == NULL){
        return ans;
    }

    Node* left = head;
    Node* right = findTail(head); //o(n)

    while(left->data < right->data){ //o(n)
        if(left->data + right->data == k){
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        }
        else if(left->data + right->data < k){
            left = left->next;
        }else{
            right = right->prev;
        }
    }
    return ans;
}

//explained by striver: https://takeuforward.org/linked-list/top-linkedlist-interview-questions-structured-path-with-video-solutions/