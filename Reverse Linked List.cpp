/*
 * Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
	    ListNode *_head = head;
	    bool flag = false;
	    while (head && head->next) {
		    if(cur->next->next == NULL) {
			    if (!flag) {
				    flag = true;
				    _head = cur->next;
			    }
		    	cur->next->next = cur;
			    cur->next = NULL;
			    cur = head;
		    } else {
			cur = cur->next;
		    }
	    }
	    return _head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *h = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
	    ListNode *p1 = NULL;
	    ListNode *p2 = NULL;
	    ListNode *cur = head;
    	while(1) {
		    p2 = cur->next;
		    cur->next = p1;
		    p1 = cur;
		    if(p2 == NULL) break;
		    cur = p2;
	    }
	    return cur;
};
