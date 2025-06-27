class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 定义比较器：创建小顶堆
        // 小顶堆确保堆顶始终是最小元素
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // 返回true表示a的优先级低于b
        };
        
        // 创建优先队列（小顶堆）
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // 将所有非空链表的头节点加入堆
        // 这样堆顶就是当前所有链表头节点中的最小值
        for(ListNode* list : lists) {
            if(list) {
                pq.push(list);
            }
        }
        
        // 创建虚拟头节点，简化链表操作
        ListNode dummy;
        ListNode* tail = &dummy;
        
        // 当堆不为空时，继续合并
        while(!pq.empty()) {
            // 1. 获取当前最小节点
            ListNode* minNode = pq.top();
            pq.pop();
            
            // 2. 将最小节点连接到结果链表
            tail->next = minNode;
            tail = tail->next;
            
            // 3. 如果最小节点有后续节点，将后续节点加入堆
            // 这样保证堆中始终包含每个链表的"当前最小"节点
            if(minNode->next) {
                pq.push(minNode->next);
            }
        }
        
        return dummy.next;
    }
};