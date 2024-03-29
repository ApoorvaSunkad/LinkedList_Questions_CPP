/*
Given elements as nodes of the two linked lists. The task is to multiply these 
two linked lists, say L1 and L2. 

Note: The output could be large take modulo 109+7.

Example:

Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 
Output:
64
1000

Explanation:
Testcase 1: 32*2 = 64.
Testcase 2: 100*10 = 1000.
Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow, the first line of each test case contains an integer N 
denoting the size of the first linked list (L1). In the next line are the 
space-separated values of the first linked list. The third line of each test 
case contains an integer M denoting the size of the second linked list (L2). 
In the fourth line is space-separated values of the second linked list.

Output:
For each test case output will be an integer denoting the product of the two 
linked lists.

Your Task:
The task is to complete the function multiplyTwoLists() which should multiply 
the given two linked lists and return the result.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

*/

#include<bits/stdc++.h>
using namespace std;

//My solution

//T.C = O(2N) = O(N)
//S.C = O(1)

long long  multiplyTwoLists (Node* l1, Node* l2)
{
  
   long long ans1 = 0;
   long long ans2 = 0;
   const long long MOD = 1000000007;
  
   Node* temp1 = l1;
   Node* temp2 = l2;
  
    while(temp1!=NULL){
      ans1 = (ans1*10 + temp1->data) % MOD;
      temp1 = temp1->next;
    }
  
    while(temp2!=NULL){
      ans2 = (ans2*10 + temp2->data) % MOD;
      temp2 = temp2->next;
    }
    
    long long prod = (ans1 * ans2) % MOD;
    
    return prod;
  
}