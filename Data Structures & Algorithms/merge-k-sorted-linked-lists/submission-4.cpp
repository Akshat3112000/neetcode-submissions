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


        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

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

        return dummy -> next;
    }
   ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int last = lists.size() - 1;
        while (last > 0) {
            int i = 0;
            int j = last;
            
            while (i < j) {
                lists[i] = merge2Lists(lists[i], lists[j]);
                i++;
                j--;
            }
            last = j; 
        }
        return lists[0];
    }
};
