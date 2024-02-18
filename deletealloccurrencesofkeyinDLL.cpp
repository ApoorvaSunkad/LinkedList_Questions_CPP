/*
Problem statement
A doubly-linked list is a data structure that consists of sequentially linked 
nodes, and the nodes have reference to both the previous and the next nodes in 
the sequence of nodes.



You’re given a doubly-linked list and a key 'k'.



Delete all the nodes having data equal to ‘k’.



Example:
Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10

Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20

Explanation: All the nodes having ‘data’ = 10 are removed from the linked list.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
10 4 10 3 5 20 10
10


Sample Output 1:
4 3 5 20


Explanation Of Sample Input 1:
All the nodes having ‘data’ = 10 are removed from the linked list.


Sample Input 2:
7
10 4 10 3 5 20 10
30


Sample Output 2:
10 4 10 3 5 20 10


Explanation Of Sample Input 2:
The linked list does not have any node with ‘data’ = 30. So the linked list is 
unchanged.


Expected Time Complexity:
The expected time complexity is O(‘n’).


Constraints:
0 <= ‘n’ <= 100000
1 <= ‘data’ in any node <= 10^9
1 <= ‘k’ <= 10^9

*/

//T.C = O(N)
//S.C = O(1)

Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == k){
            if(temp == head){
                head = temp->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if(nextNode!=NULL){
                nextNode->prev = prevNode;
            }
            if(prevNode!=NULL){
                prevNode->next = nextNode;
            }
            free(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}