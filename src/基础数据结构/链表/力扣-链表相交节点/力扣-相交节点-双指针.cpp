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
        
        ListNode* PA = headA;
        ListNode* PB = headB;
        //PA走到终点 将PA指向headB
        //PB走到终点 将PB指向headA

        //这样 一定会走到相同的节点 （或者空节点）
        while(PA != PB)
        {
            PA = (PA==nullptr ? headB : PA->next);
            PB = (PB==nullptr ? headA : PB->next);
        }

        return PA; //要么为空节点 要么是相同的节点
    
        
    }
};