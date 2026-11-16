class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous_node = nullptr;
        while(head != nullptr){
            ListNode* next_head = head->next;
            head->next = previous_node;
            previous_node = head;
            head = next_head;
        }
        return previous_node;
    }
};
