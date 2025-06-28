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
    ListNode* frontPointer;
    bool recursivelyCheck(ListNode* currentNode) {
        if(currentNode != nullptr)
        {
            //一层一层往下走
            if(!recursivelyCheck(currentNode->next))
            {
                return false; //上一层返回false了，代表已经检测到不满足 所有返回false
            }
            if(currentNode->val != frontPointer->val) return false;
            frontPointer = frontPointer->next;  //从后往前回去的时候，每回去一层，frontPointer完后走一个，相当于双指针往中间聚拢

        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);

        return true;
    }
};