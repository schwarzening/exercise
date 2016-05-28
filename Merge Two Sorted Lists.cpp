/* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the 
 * nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return l1;
        if(l1 == NULL && l2 != NULL) return l2;
        if(l1 != NULL && l2 == NULL) return l1;
		if(l1->val > l2->val ) swap(l1,l2);
        ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		ListNode* next2;
		while(cur2) {
			if(cur2->val >= cur1->val && cur1->next == NULL) {
				cur1->next = cur2;
				break;
			} else if(cur2->val >= cur1->val && cur2->val <= cur1->next->val) {
				next2 = cur2->next;
				cur2->next = cur1->next;
				cur1->next = cur2;
				cur2 = next2;	
			} else {
				cur1 = cur1->next;
			}
		}
		return l1;
    }
};
