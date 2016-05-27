/* Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 * Example:
 *  Given 1->2->3->4->5->NULL,
 *  return 1->3->5->2->4->NULL.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!(head && head->next)) return head;
	    ListNode *cur1, *cur2, *_head;
	    cur1 = head;
	    cur2 = cur1->next;
	    _head = cur2;

	    while ((cur1 != NULL) && (cur2 != NULL)) {	
		    cur1->next = cur1->next->next;
		    if(cur1->next != NULL) cur1 = cur1->next;
		    if(cur2->next == NULL) {
			    //cur2->next = NULL;
			    cur2 = cur2->next;
		    } else {
		    	cur2->next = cur2->next->next;
			    cur2 = cur2->next;
		    }
	    }
	    cur1->next = _head;
    	return head;
    }
};
