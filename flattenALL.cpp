/*
Problem statement
You are given a linked list containing 'n' 'head' nodes, where every node in the 
linked list contains two pointers:



(1) ‘next’ which points to the next node in the list

(2) ‘child’ pointer to a linked list where the current node is the head.



Each of these child linked lists is in sorted order and connected by 'child' pointer.



Your task is to flatten this linked such that all nodes appear in a single layer or 
level in a 'sorted order'.



Example:
Input: Given linked list is:

Output:
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 12 → 20 → null.


Explanation:
The returned linked list should be in a sorted order. All the elements in this returned 
linked list are connected by 'child' pointers and 'next' pointers point to null.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4
3
1 2 3
3
8 10 15
2
18 22
1
29


Sample Output 1 :
1 2 3 8 10 15 18 22 29


Explanation For Sample Input 1:
The given linked list is 

Therefore after flattening the list will become-
1 -> 2 -> 3 -> 8 -> 10 -> 15 -> 18 -> 22 -> 29 ->null


Sample Input 2 :
5
2
4 6
2
5 71
3
7 8 9
3 
11 12 19
3
14 15 17


Sample Output 2 :
4 5 6 7 8 9 11 12 14 15 17 19 71


Expected Time Complexity:
Try solving this in O(n*n*k), where ‘n’ denotes the number of head nodes and ‘k’ 
is the average number of child nodes in all 'n' sub-lists.     


Expected Space Complexity:
Try solving this without using any extra space.   


Constraints:
1 <= n <= 100
1 <= k <= 20
1 <= Node.data <= 10^9

Time Limit: 1 sec


*/


//Refer coding Ninjas for the question


//Brute force:
//T.C = O(N*M)*2 + O(XLOGX) //why N and M bcz N is horizontal list and M is vertical list
//S.C = O(N*M)*2 why * 2 bcz we are taking a node and creating a vertical LL

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<bits/stdc++.h>
Node* convertArrtoLL(vector<int>ans){
	if(ans.size() == 0){
		return nullptr;
	}

	int n = ans.size();
	Node* head = new Node(ans[0]);
	Node* temp = head;
	for(int i = 1; i<n;i++){
		Node* newNode = new Node(ans[i]);
		temp->child = newNode;
		temp = temp->child;
	}
	return head;
}
Node* flattenLinkedList(Node* head) 
{
	vector<int> v;

	Node* temp = head;

	while(temp!=nullptr){
		Node* t2 = temp;
		while(t2!=nullptr){
			v.push_back(t2->data);
			t2 = t2->child;
		}
		temp = temp->next;
	}

	sort(v.begin(),v.end());

	head = convertArrtoLL(v);
	return head;

}


//Optimised solution: Using Recursion and backtracking

//T.C = O(N) * O(2M)
//S.C = O(N)
Node* merge(Node* head1, Node* head2){
	Node* dummyNode = new Node(-1);

	Node* res = dummyNode;

	while(head1!=nullptr && head2!=nullptr){
		if(head1->data < head2->data){
			res->child = head1;
			res = head1;
			head1 = head1->child;
		}
		else{
			res->child = head2;
			res = head2;
			head2 = head2->child;
		}
		res->next = nullptr;
	}

	if(head1) res->child = head1;
	else res->child = head2;

	if(dummyNode->child) dummyNode->child->next = nullptr;
	return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	//Base case
	if(head == nullptr || head->next == nullptr){
		return head;
	}

	//Recursive call
	Node* mergeHead = flattenLinkedList(head->next);

	//Backtrack
	head = merge(head, mergeHead);
	return head;
}

