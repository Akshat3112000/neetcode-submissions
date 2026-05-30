class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node simplifies handling the new head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* beforeGroup = dummy;
        ListNode* cur = head;

        // 1. Count total nodes in the list
        int totalNodes = 0;
        while (cur) {
            totalNodes++;
            cur = cur->next;
        }

        // 2. Loop and reverse in groups of k
        while (totalNodes >= k) {
            ListNode* groupHead = beforeGroup->next;
            ListNode* prv = nullptr;
            cur = groupHead;

            // Standard in-place reversal for k nodes
            for (int i = 0; i < k; i++) {
                ListNode* nxt = cur->next;
                cur->next = prv;
                prv = cur;
                cur = nxt;
            }

            // 3. Stitch the reversed group back into the list
            beforeGroup->next = prv;   
            beforeGroup = groupHead;       
            beforeGroup->next = cur;         
            
            totalNodes -= k;               // Reduce remaining node count
        }

        ListNode* newHead = dummy->next;
        delete dummy;                      // Clean up heap allocation
        return newHead;
    }
};