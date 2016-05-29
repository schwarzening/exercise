/*
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    int len(ListNode *head) {
		int count = 0;
		while(head) {
			count ++;
			head = head->next;
		}
		return count;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return l1;
        if(l1 != NULL && l2 == NULL) return l1;
        if(l1 == NULL && l2 != NULL) return l2;
		if(len(l1) < len(l2)) swap(l1,l2);
		ListNode *cur1, *cur2;
		int tmp, tmp2;
		cur1 = l1; cur2 = l2;
		int carry = 0;
		ListNode *head, *cur, *_next;
		head = new ListNode(0);
		cur = head;
		while(1) {
			if(cur2) {
				tmp2 = cur2->val;
			} else {
				tmp2 = 0;
			}
			tmp = cur1->val + tmp2 + carry;
			if(tmp < 10){
				cur->val = tmp;
				carry = 0;
			} else {
				cur->val = tmp - 10;
				carry = 1;
			}
			cur1 = cur1->next;
			if(cur2 != NULL) cur2 = cur2->next;
			if(cur1 == NULL) break;
			_next = new ListNode(0);
			cur->next = _next;
			cur = cur->next;
		}
		if(carry) {
			_next = new ListNode(1);
			cur->next = _next;
		}
		return head;
    }
};
