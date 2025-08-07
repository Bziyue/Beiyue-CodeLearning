/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA== nullptr || headB==nullptr) return nullptr;
        unordered_set<ListNode*>  hash_A;
        auto temp = headA;
        while(temp != nullptr)
        {
            hash_A.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr)
        {
            if(hash_A.contains(temp)) return temp;
            temp = temp->next;
        }

        return nullptr;
        
    }
};