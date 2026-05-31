class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // 1. Find the middle of the list using Slow & Fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* cur = slow->next;
        slow->next = nullptr;

        // 2. Reverse the second half in-place
        ListNode* prv = nullptr;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }

        // 3. Interleave/Merge the two halves cleanly
        cur = head;

        while (cur && prv) {
            ListNode* nxt1 = cur->next;
            ListNode* nxt2 = prv->next;

            cur->next = prv;
            prv->next = nxt1;

            cur = nxt1;
            prv = nxt2;
        }
    }
};