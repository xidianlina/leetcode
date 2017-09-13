/*
Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/

#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x),next(NULL){}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1)
			return head;
		ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy, *cur = head;
		dummy->next = head;
		int i = 0;
		while (cur)
		{
			++i;
			if (i%k == 0)
			{
				pre = reverseOneGroup(pre, cur->next);
				cur = pre->next;
			}
			else
				cur = cur->next;
		}
		return dummy->next;
	}
	ListNode* reverseOneGroup(ListNode* pre, ListNode* next)
	{
		ListNode* last = pre->next;
		ListNode* cur = last->next;
		while (cur != next) {
			last->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = last->next;
		}
		return last;
	}
};