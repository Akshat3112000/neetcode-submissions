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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* cur = head;
        while(cur && cnt < k)
        {
            cnt++;
            cur = cur -> next;
        }

        if(cnt < k)
        {
            return head;
        }

        cur = head;
        cnt = 0;
        ListNode* prv = nullptr;

        while(cur && cnt < k)
        {
           ListNode* nxt = cur -> next;
           cur -> next = prv;
           prv = cur;
           cur = nxt; 
           cnt++;
        }

        head -> next = reverseKGroup(cur,k);

        return prv;
    }
};
