/* Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 *  Could you do it in O(n) time and O(1) space?
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
    ListNode* middle(ListNode *head){
    	ListNode *p, *q;
    	p = q = head;
    	while(q && q->next) {
    		p = p->next;
    		q = q->next->next;
    	}
    	return p;
    }

    ListNode* reverse(ListNode *head) {
    	if(head == NULL || head->next == NULL) return head;
    	ListNode *p1 = NULL;
    	ListNode *p2;
    	ListNode *cur = head;
    	while(1) {
       		p2 = cur->next;
    		cur->next = p1;
    		p1 = cur;
    		if(p2 == NULL) break;
    		cur = p2;
    	}
    	return cur;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
	    ListNode *mid = middle(head);
	    ListNode *after_re = reverse(mid);
    	while(head && after_re) {
		    if (head->val != after_re->val ) return false;
	    	head = head->next;
	    	after_re = after_re->next;
	    }
    	return true;
    }
};
