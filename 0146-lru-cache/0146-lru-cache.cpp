class LRUCache {
public:
    class Node {
        public:
            int val, key;
            Node* prev;
            Node* next;

            Node(int key, int val) {
                this->key = key;
                this->val = val;
                next = prev = NULL;
            }
    };
    unordered_map<int, Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int limit;

    void addNode(Node* newnode) {
        Node* nodenext = head->next;
        head->next = newnode;
        nodenext->prev = newnode;
        newnode->next = nodenext;
        newnode->prev = head;
        
    }
    void deleteNode(Node* oldnode) {
        Node* nodeprev = oldnode->prev;
        Node* nodenext = oldnode->next;
        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
        // delete oldnode;

    }
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        int value = m[key]->val;
        Node* newnode = m[key];
        deleteNode(m[key]);
        addNode(m[key]);
        return value;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) { //m.end is out of scope and if m.find(key) != end then key exist its valid
            Node* oldnode = m[key];
            m.erase(key);
            deleteNode(oldnode);
        }
        if(m.size() == limit) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev); //always del last ele least used
        }
        Node* newnode = new Node(key, value);
        addNode(newnode);
        m[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */