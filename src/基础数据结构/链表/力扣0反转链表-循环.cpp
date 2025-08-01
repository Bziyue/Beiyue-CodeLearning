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

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre,*current,*next;
        current = head;pre =nullptr;next = current->next;
        while(current != nullptr)
        {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};