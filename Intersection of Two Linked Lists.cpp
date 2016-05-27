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
    int len(ListNode *head){
		int len = 0;
		while(head) {
			len++;
			head = head->next;
		}
		return len;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
		int lenB = len(headB);
		if(lenA > lenB) swap(headA,headB);
		int _abs = len(headB) - len(headA);
		while(_abs--) {
			headB = headB->next;
		}
		while(headA && headB) {
			if(headA == headB) return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
    }
};
