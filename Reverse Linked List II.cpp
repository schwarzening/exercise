/* Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 *   Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *   return 1->4->3->2->5->NULL.
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
    ListNode* index(ListNode *head, int i) {
		if(i == 0) return NULL;
		int cnt = 1;
		while(head) {
			if(cnt == i) break; 
			cnt ++;
			head = head->next;
		}
		return head;
	}
	
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(head == NULL || head->next == NULL) return head;
		ListNode *cur, *p1, *p2, *node_m, *node_n;
		if(m == 1) {
			node_n = index(head, n + 1);
			p1 = NULL;
			cur = p2 = head;
			while(1) {
				p2 = cur->next;
				cur->next = p1;
				p1 = cur;
				if(p2 == node_n) break;
				cur = p2;
			}
			p1 = index(cur, n);
			p1->next = node_n;
			return cur;
		}		
		node_m = index(head, m - 1);
		cur = p2 = node_m->next;
		node_n = index(head, n + 1);
		p1 = node_n;
		while(1) {
			p2 = cur->next;
			cur->next = p1;
			p1 = cur;
			if (p2 == node_n) break;
			cur = p2;	
		}
		node_m->next = cur;
		return head;
	}
};
