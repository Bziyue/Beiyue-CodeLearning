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
        // if(head->next == nullptr) return head;
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* new_head = reverseList(head->next);//找到链表的尾巴
        ListNode* tail = head->next; //当前节点的下一个节点
        tail->next = head; //下一个节点指向当前节点
        head->next = nullptr;//使得当前节点的下一个节点展示为空
        return new_head;
    }
};