class LRUCache {

public:
    class Node {
        public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = next = NULL;
        }
    };
    

    unordered_map<int, Node*> lru;
    int limit;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }
    void deleteNode(Node* node) {
        Node* oldNext = node->next;
        Node* oldprev = node->prev;

        node->next->prev = oldprev;
        node->prev->next = oldNext;
    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (lru.find(key) == lru.end())
            return -1;
        Node* ansNode = lru[key];
        int ans = ansNode->val ;
        deleteNode(ansNode);
        addNode(ansNode);
       

        return ans;
    }

    void put(int key, int val) {
        if (lru.find(key) != lru.end()) {
            Node* oldNode = lru[key];
            lru.erase(key);
            deleteNode(oldNode);
        }
        if (lru.size() == limit) {
            lru.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, val);
        addNode(newNode);
        lru[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
