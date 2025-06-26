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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> pointers = lists;
        ListNode* mergedlists = new ListNode;
        ListNode* head = mergedlists;

        while(!all_of(pointers.begin(),pointers.end(),[](ListNode* pointer){return pointer == nullptr;})) //判断是否全部为nullptr
        //如果是，表示所有的指针都走到头了
        {
            //在k个有效指针中遍历，找到最小的元素
            //先定义一个理论上最大的元素
            int min_num = numeric_limits<int>::max();
            auto min_iter = pointers.begin();
            for(auto iter = pointers.begin();iter != pointers.end();++iter) //通过迭代器在所有的指针中便利，找到最小的元素并且找到指向最小元素指针的迭代器
            {
                if (*iter != nullptr) //判断当前指针是否有效
                {
                    if((*iter)->val < min_num)
                    {
                        min_num = (*iter)->val;
                        min_iter = iter; //更新指向最小元素指针的迭代器
                    }
                }
            }
            if(min_num != numeric_limits<int>::max())
            {
                //找到了有效元素，那么添加到合并链表的末尾，并且该指针往后移动
                mergedlists->next = *min_iter; //避免创建新的对象
                mergedlists = mergedlists->next;
                *min_iter = (*min_iter)->next;
            }
        }

        return head->next;

    }
};