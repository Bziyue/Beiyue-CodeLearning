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
class Solution {
public:
    ListNode* reverseList_recursion(ListNode* pre,ListNode* current)
    {
        if(current->next == nullptr)
        {
            current->next = pre;
            return current;
        }
        else
        {
            auto head = reverseList_recursion(current,current->next);
            current->next = pre;
            return head;
        }
    }
    ListNode* reverseList(ListNode* head) {
        // if(head->next == nullptr) return head;
        if (head == nullptr) return nullptr;
        return reverseList_recursion(nullptr,head);

    }
};