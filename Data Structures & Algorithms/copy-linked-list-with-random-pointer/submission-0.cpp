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
        Node* _list = head;
        Node dummy(0);
        Node* previous_node = &dummy;
        
        unordered_map<Node*, Node*> random_pointers;
        random_pointers[nullptr] = nullptr;
        while(_list != nullptr){
            Node* new_node = new Node(_list->val);
            previous_node->next = new_node;
            previous_node = new_node;

            random_pointers[_list] = new_node;

            _list = _list->next;
        }

        _list = head;
        previous_node = dummy.next;
        while(_list != nullptr){
            previous_node->random = random_pointers[_list->random];
            _list = _list->next;
            previous_node = previous_node->next;
        }

        return dummy.next;
    }
};
