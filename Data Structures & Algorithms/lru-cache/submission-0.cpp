class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k) , val(v) , prev(nullptr) , next(nullptr){}
    };

    int capacity;
    unordered_map<int,Node*> cache;

    Node* head;
    Node* tail;

    void add(Node* x)
    {
        Node* nxt = head -> next;

        head -> next = x;
        nxt -> prev = x;

        x -> next = nxt;
        x -> prev = head;
    }

    void remove(Node* x)
    {
        x -> prev -> next = x -> next;
        x -> next -> prev = x -> prev;
    }

    void move(Node* x)
    {
        remove(x);
        add(x);
    }

public:
    
    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int k) {
        if(cache.find(k) == cache.end())
        {
            return -1;
        }

        Node* node = cache[k];
        move(node);
        return node -> val;
    }
    
    void put(int k, int v) {
        if(cache.find(k) != cache.end())
        {
            Node* node = cache[k];
            move(node);
            node -> val = v;
            return;
        }

        if(cache.size() == capacity)
        {
            Node* node = tail -> prev;
            cache.erase(node -> key);
            remove(node);
            delete node;
        }

        Node* node = new Node(k,v);
        cache[k] = node;
        add(node);
    }

    ~LRUCache() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current; // Cleanly destroys every remaining node
        current = nextNode;
    }
}
};
