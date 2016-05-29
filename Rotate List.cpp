/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 *  Given 1->2->3->4->5->NULL and k = 2,
 *  return 4->5->1->2->3->NULL.
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
    int length(ListNode *head) {
		int count = 0;
		while(head) {
			count ++;
			head = head->next;
		}
		return count;
	}
	ListNode* index(ListNode *head, int i) {
		int cnt = 0;
		while(head) {
			if(cnt == i) return head; 
			cnt ++;
			head = head->next;
		}
		return head;
	}
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int len = length(head);
		k %= len;
		ListNode *last = index(head, len - 1);
		last->next = head;
		ListNode *_last = index(head, len - 1 - k);
		ListNode *_head = _last->next;
		_last->next = NULL;
		return _head;
    }
};
