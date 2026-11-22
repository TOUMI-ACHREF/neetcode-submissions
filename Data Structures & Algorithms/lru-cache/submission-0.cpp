class LRUCache {
private:
    struct Node {
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<int, Node*>position;
    Node* cache_head;
    Node* cache_tail;
    int capacity;
    int current_capacity;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }       
    void insertAtHead(Node* node) {
        node->next = cache_head->next;
        node->prev = cache_head;

        cache_head->next->prev = node;
        cache_head->next = node;
    }    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        current_capacity = 0;
        cache_head = new Node(-1, -1);
        cache_tail = new Node(-1, -1);

        cache_head->next = cache_tail;
        cache_tail->prev = cache_head;
    }
    

    int get(int key) {
        if(position.find(key) == position.end()) return -1;
        else {
            removeNode(position[key]);
            insertAtHead(position[key]);
            return position[key]->value;
        }
    }
    
    void put(int key, int value) {
        if(position.find(key) == position.end()){//doesn't exist
            if (current_capacity == capacity) {
                Node* lru = cache_tail->prev;
                position.erase(lru->key);
                removeNode(lru);
                delete lru;
            } else {
                current_capacity++;
            }

            Node* new_element = new Node(key, value);
            position[key] = new_element;
            insertAtHead(new_element);
        }else{
            Node* current_pos = position[key];
            current_pos->value = value;
            //update list
            removeNode(current_pos);
            insertAtHead(current_pos);
        }
    }
};
