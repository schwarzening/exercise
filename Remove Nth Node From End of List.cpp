/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 *  Given linked list: 1->2->3->4->5, and n = 2.
 *  After removing the second node from the end, the linked list becomes 1->2->3->5.
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
			if(cnt == i) break; 
			cnt ++;
			head = head->next;
		}
		return head;
	}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
		if(head->next == NULL && n == 1) return head->next;
		ListNode dummy = ListNode(-1);
		dummy.next = head;
		int len = length(head);
		ListNode *del = index(head,len - n);
		ListNode *pre = &dummy;
		while(pre->next != del) {
			pre = pre->next;
		}
		pre->next = pre->next->next;
		delete del;
		return dummy.next;
    }
};
