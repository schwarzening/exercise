/* Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 *  Given 1->1->2, return 1->2.
 *  Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
		int tmp = head->val;
		ListNode *cur = head;
		ListNode *del;
		while(cur->next) {
			if(cur->next->val == tmp) {
				del = cur->next;
				cur->next = cur->next->next;
				delete del;
			} else {
				tmp = cur->next->val;
				cur = cur->next;
			}
		}
		return head;
    }
};
