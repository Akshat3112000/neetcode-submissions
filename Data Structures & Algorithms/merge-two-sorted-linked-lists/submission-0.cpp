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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;

        ListNode* tmp = new ListNode(0);
        ListNode* cur = tmp;

        while(a && b)
        {
            if(a -> val < b -> val)
            {
                cur -> next = a;
                a = a -> next;
            }
            else
            {
                cur -> next = b;
                b = b -> next;
            }
            cur = cur -> next;
        }
        cur -> next = a ? a:b;
        return tmp -> next;
    }
};
