class Solution
{
public:
    ListNode* findmid(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next; //fast走得快 所以走过的路程时slow的两倍
        }

        return slow;
    }

    ListNode* reverse_list(ListNode *head)
    {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr)
        {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
        
    }
    bool isPalindrome(ListNode *head)
    {
        auto mid = findmid(head);
        //反转
        auto head2 = reverse_list(mid);
        //如果为计数节点 那么在中间 如果为偶数节点 那么在中间两个的右边
        while(head2)
        {
            if(head->val != head2->val)
            {
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};