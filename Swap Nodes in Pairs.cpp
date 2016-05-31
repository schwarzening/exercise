/* Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 *   Given 1->2->3->4, you should return the list as 2->1->4->3.
 *   Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy = ListNode(-1);
		dummy.next = head;
		if(dummy.next == NULL || dummy.next->next == NULL) return dummy.next;
		ListNode *tmp, *pre = &dummy;
		while(pre->next->next != NULL) {
			if(pre->next == NULL) break;
			tmp = pre->next;
			pre->next = pre->next->next;
			tmp->next = pre->next->next;
			pre->next->next = tmp;
			pre = pre->next->next;
			if(pre->next == NULL) break;
		}
		return dummy.next;
    }
};
