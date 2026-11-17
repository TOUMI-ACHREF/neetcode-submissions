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
    void reorderList(ListNode* head) {
        //detect the point for splitting the List
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        //in the end slow contains the half element
        ListNode* list2 = slow->next;
        slow->next = nullptr;

        // reverse
        ListNode* previous = nullptr;
        while (list2!=nullptr){
            ListNode* next_head = list2->next;
            list2->next = previous;
            previous = list2;
            list2 = next_head;
        }//head = list2 in the end
        ListNode* first = head;
        ListNode* second = previous;

        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
