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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* sum_list = &dummy;
        int rest = 0;
        while(l1!=nullptr && l2!=nullptr){
            ListNode* new_node = new ListNode((l1->val+l2->val+rest)%10);
            rest = (l1->val+l2->val+rest)/10;
            l1 = l1->next;
            l2 = l2->next;
            sum_list->next = new_node;
            sum_list = sum_list->next; 
        }
        while(l1!=nullptr){
            ListNode* new_node = new ListNode((l1->val + rest) % 10);
            rest = (l1->val+rest)/10;
            l1 = l1->next;
            sum_list->next = new_node;
            sum_list = sum_list->next;  
        }
        while(l2!=nullptr){
            ListNode* new_node = new ListNode((l2->val+rest)%10);
            rest = (l2->val+rest)/10;
            l2 = l2->next;
            sum_list->next = new_node;
            sum_list = sum_list->next;  
        }
        if (rest > 0) {
            sum_list->next = new ListNode(rest);
        }
        return dummy.next;
    }
};
