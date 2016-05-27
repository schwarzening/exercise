/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode _pre(-1);
        _pre.next = head;
        ListNode* pre = &_pre;
        while(pre->next) {
            if(pre->next->val == val) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return _pre.next;
    }
    ListNode* removeElements(ListNode* head, int val) {
        static ListNode pre(-1);
        pre.next = head;
        ListNode* _cur = &pre;
        ListNode* cur = head;
        if (cur == NULL) return cur;
        while(cur->next != NULL) {
            if(cur->val == val) {
                cur->val = cur->next->val;
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
                _cur = _cur->next;
            }
        }
        if(cur->val == val) {
            _cur->next = NULL;
        }
        return pre.next;
    }
};
