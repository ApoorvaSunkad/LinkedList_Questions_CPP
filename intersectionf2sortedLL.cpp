/*
Given two linked lists sorted in increasing order, create a new linked list 
representing the intersection of the two linked lists. The new linked list should 
be made with without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Example 1:

Input:
LinkedList1 = 1->2->3->4->6
LinkedList2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
LinkedList1 = 10->20->40->50
LinkedList2 = 15->40
Output: 40
Your Task:
You don't have to take any input of print anything. Your task is to complete the 
function findIntersection(), which will take head of both of the linked lists as 
input and should find the intersection of two linked list and add all the elements 
in intersection to the third linked list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n, m are the size of the respective linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 10^4

*/

//Brute force:using maps
//T.C = O(N+M)
//S.C = O(N) only 1 LL is added to map
Node* findIntersection(Node* head1, Node* head2) {

    Node* tmp1 = head1;
    Node* tmp2 = head2;

    Node* result = new Node(0);
    Node* curr = result;

    std::unordered_map<int, int> set;

    while (tmp1 != nullptr) {
        set[tmp1->data] = set[tmp1->data] + 1;
        tmp1 = tmp1->next;
    }

    while (tmp2 != nullptr) {
        if (set.find(tmp2->data) != set.end()) {
            set[tmp2->data] = set[tmp2->data] - 1;
            if (set[tmp2->data] == 0) {
                set.erase(tmp2->data);
            }
            curr->next = new Node(tmp2->data);
            curr = curr->next;
        }
        tmp2 = tmp2->next;
    }

    result = result->next;
    return result;
}

//Expected approach
//T.C = O(N+M)
//S.C = O(N+M)

Node* findIntersection(Node* head1, Node* head2){

    if(head1==NULL || head2==NULL){
        return NULL;
    }
    

    Node* temp1 = head1;
    Node* temp2 = head2;

    // Create a new linked list using elements from the set
    Node* dummyNode = new Node(-1);
    Node* mover = dummyNode;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data==temp2->data){
            mover->next = new Node(temp1->data);;
            mover = mover->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data){
            temp1=temp1->next;
        }else{
            temp2= temp2->next;
        }
    }

    return dummyNode->next;
}