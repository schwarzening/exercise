/* Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return head;
		ListNode *cur1, *cur2;
		cur1 = cur2 = head;
		bool _ret = false;
		while(cur2 && cur2->next) {
			if(cur1 == cur2 && _ret) return true;
			else {
				_ret = true;
				cur1 = cur1->next;
				cur2 = cur2->next->next;
			}
		}
		return false;
    }
};
