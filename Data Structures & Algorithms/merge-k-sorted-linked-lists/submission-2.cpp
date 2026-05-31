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
    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;


        ListNode* head;

        if (a->val < b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }

        ListNode* cur = head;

        while (a && b) {
            if (a->val < b->val) {
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }

        cur->next = a ? a : b;

        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return nullptr;
        }
        int x = 0;
        while (k != 1) {
            for (int i = 0; i < k - 1; i += 2) {
                lists[x] = merge2Lists(lists[i], lists[i + 1]);
                x++;
            }
            if (k & 1) lists[x] = lists[k - 1];

            k = (k + 1) >> 1;
            x = 0;
        }
        return lists[0];
    }
};
