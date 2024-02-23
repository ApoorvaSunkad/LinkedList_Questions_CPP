/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending 
order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.

*/

//Brute force:
//T.C = O(N*K) + O(MLOGM) + O(M) where M is N*K
//S.C = O(M) + O(M)

ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0){
            return NULL;
        }

        vector<int> v;

        //O(K) 
        for(int i = 0; i<lists.size();i++){
            ListNode* temp = lists[i];

            while(temp!=NULL){ //O(N)
                v.push_back(temp->val);
                temp = temp->next;
            }//O(N*K)
        }
        sort(v.begin(),v.end()); //O(MLOGM) = O(N*K)

        //convert arr to LL

        ListNode* dummyNode = new ListNode(-1);
        ListNode* mover = dummyNode;

        for(int i = 0; i<v.size();i++){  //O(M) = O(N*K)
            ListNode* temp = new ListNode(v[i]);

            mover->next = temp;
            mover = temp;
        }
        return dummyNode->next;
}

//Better solution
//T.C = O(N) * O(K * (K+1))/2 ~ O(N^3)
//S.C = O(1)

ListNode* merge2Lists(ListNode* head1, ListNode* head2){

    ListNode* temp1 = head1;
    ListNode* temp2 = head2;

    ListNode* dummyNode = new ListNode(-1);
    ListNode* res = dummyNode;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val < temp2->val){
            res->next = temp1;
            res = temp1;
            temp1 = temp1->next;
        }
        else{
            res->next = temp2;
            res = temp2;
            temp2 = temp2->next;
        }
    }
    if(temp1!=NULL){
        res->next = temp1;
    }
    else{
        res->next = temp2;
    }

    return dummyNode->next;
}
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    if(lists.size() == 0){
        return NULL;
    }
    ListNode* head = lists[0];

    for(int i = 1; i<lists.size();i++){
        head = merge2Lists(head, lists[i]);
    }
    return head;
}


//Optimised solution: 
//Using min Heap meaning priority qeueue

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

    for(int i = 0; i<lists.size();i++){
        if(lists[i]){
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->val, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}