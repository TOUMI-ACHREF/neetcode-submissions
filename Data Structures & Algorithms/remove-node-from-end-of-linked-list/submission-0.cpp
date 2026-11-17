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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* _list = head;
        int length = 0;
        while(_list != nullptr){
            _list = _list->next;
            length++;
        }
        // if we should remove the head
        if (length == n) {
            return head->next;
        }

        _list = head;
        length-=n;
        while(length > 1){
            _list = _list->next;
            length--;
        }
        _list->next = _list->next->next;
        return head;
    }
};
