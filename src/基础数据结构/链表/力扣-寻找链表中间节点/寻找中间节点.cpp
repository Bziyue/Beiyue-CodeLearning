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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast,*slow;
        fast=slow=head; //快慢指针，利用fast的移动速度是 slow的两倍 那么fast到尾部 slow一定到中间
        while(fast != nullptr && fast->next != nullptr) //思路类似于链表的导数第K个节点 fast往前移动k步，此时slow再开始移动，那么二者的间距为k fast到末尾 slow到倒数第k个
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};