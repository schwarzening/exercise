/* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * For example,
 *  Given 1->2->3->3->4->4->5, return 1->2->5.
 *  Given 1->1->1->2->3, return 2->3.
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
    ListNode *next(ListNode *head, int n) {
		ListNode *del;
		while(head && head->val == n) {
			del = head;
			head = head->next;
			delete del;
		}
		return head;
	}
	
	ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode dummy = ListNode(-1);
		dummy.next = head;
		ListNode *pre = &dummy;
		ListNode *_next = NULL;
		while(pre->next && pre->next->next) {
			if(pre->next->val == pre->next->next->val) {
				_next = next(pre->next, pre->next->val);
				pre->next = _next;
			} else {
				pre = pre->next;
			}		
		}
		return dummy.next;
	}
};
