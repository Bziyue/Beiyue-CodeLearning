/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == nullptr)
            return nullptr;
        vector<ListNode *> pointers;
        ListNode *node = head;
        while (node != nullptr)
        {
            pointers.push_back(node);
            node = node->next;
        }

        if (n != pointers.size()) // 不是第一个节点的情况
        {
            if (n != 1)
            {
                delete pointers[pointers.size() - n];
                pointers[pointers.size() - n - 1]->next = pointers[pointers.size() - n + 1];
            }
            else
            {
                delete pointers[pointers.size() - n];
                pointers[pointers.size() - n-1]->next=nullptr;
            }

            
        }
        else
        {
            if (pointers.size() > 1)
            {
                delete pointers[pointers.size() - n];
                head = pointers[1];
            }
            else
            {
                delete pointers[pointers.size() - n];
                head = nullptr;
            }
                
        }
        

        return head;
    }
};
int main()
{
    ListNode* head = new ListNode;
    head->next = nullptr;
    head->val = 1;

    Solution sol;
    sol.removeNthFromEnd(head,1);

    return 0;
}