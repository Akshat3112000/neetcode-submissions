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
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(a  && b )
        {
            cur -> next = new ListNode((a -> val + b -> val + carry) % 10);
            carry += a -> val + b -> val;
            carry /= 10;
            a = a -> next;
            b = b -> next;
            cur = cur -> next;
        }
        while(a)
        {
            cur -> next = new ListNode((a -> val + carry) % 10);
            carry += a -> val;
            carry /= 10;
            a = a -> next;
            cur = cur -> next;
        }
        while(b)
        {
            cur -> next = new ListNode((b -> val + carry) % 10);
            carry += b -> val;
            carry /= 10;
            b = b -> next;
            cur = cur -> next;
        }
        if(carry) cur -> next = new ListNode(carry);
        return dummy -> next;
    }
};
