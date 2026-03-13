class LFUCache {
public:
    class Node {
        public:
            int val, key, frequency;
            Node* prev;
            Node* next;

            Node(int key, int val) {
                this->key = key;
                this->val = val;
                frequency = 0;
                prev = next = nullptr;
            }
    };

    int limit = 0;
    unordered_map<int, Node*> hp;
    map<int, list<Node*>> freq;

    void addNode(Node* newnode, int freqn) {
        freq[freqn].push_front(newnode);
    }
    LFUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        if(hp.find(key) != hp.end()) {
            Node* newnode = hp[key];
            int oldfreq = newnode->frequency;

            if(freq.find(oldfreq) != freq.end()) {
                for(auto it = freq[oldfreq].begin(); it != freq[oldfreq].end(); it++) {
                    if((*it)->key == key) {
                        freq[oldfreq].erase(it);
                        break;
                    }
                }
            }
            if(freq[oldfreq].empty()) {
                freq.erase(oldfreq);
            }
            newnode->frequency += 1;
            addNode(newnode, newnode->frequency);
            return newnode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(limit == 0) {
            return;
        }
        if(hp.find(key) != hp.end()) {
            Node* node = hp[key];
            node->val = value;

            get(key);
            return;
        }
        
        if(hp.size() == limit) {
            auto it = freq.begin(); //in map 1st will be lowes freq 
            if(it != freq.end() && !it->second.empty()) {
                Node* delnode = it->second.back();
                hp.erase(delnode->key);
                it->second.pop_back();
                delete delnode;
                if(it->second.empty()) {
                    freq.erase(it);
                }
            }
        }

        Node* newnode = new Node(key,value);
        newnode->frequency = 1;
        hp[key] = newnode;
        addNode(newnode,1);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */