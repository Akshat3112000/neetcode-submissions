/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        Node* tmp = new Node(0);

        Node* res = tmp;

        unordered_map<Node*,Node*> mp;
        mp[nullptr] = nullptr;
        while(cur)
        {
            tmp -> next = new Node(cur -> val);
            tmp = tmp -> next;
            mp[cur] = tmp;
            cur = cur -> next;
        }

        cur = head;
        tmp = res;
        while(cur)
        {
            tmp -> next -> random = mp[cur -> random];
            tmp = tmp -> next;
            cur = cur -> next;
        }

        return res -> next;

    }
};
