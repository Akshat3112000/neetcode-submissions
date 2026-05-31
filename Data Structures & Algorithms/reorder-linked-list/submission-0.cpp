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
    void reorderList(ListNode* head) {
        int cnt = 0;

        ListNode* cur = head;

        while (cur) {
            cnt++;
            cur = cur->next;
        }

        cnt = (cnt - 1) >> 1;

        cur = head;

        while (cnt--) cur = cur->next;

        ListNode* cur2 = cur -> next;
        cur -> next = nullptr;

        ListNode* prv = nullptr;

        while (cur2) {
            ListNode* nxt = cur2->next;
            cur2->next = prv;
            prv = cur2;
            cur2 = nxt;
        }

        cur = head;

        while(cur && prv)
        {
            ListNode* nxt1 = cur -> next;
            ListNode* nxt2 = prv -> next;

            cur -> next = prv;
            prv -> next = nxt1;

            cur = nxt1;
            prv = nxt2;
        }
    }
};
