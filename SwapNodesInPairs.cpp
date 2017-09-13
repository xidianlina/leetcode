/*
Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.
给定一个链表，调换每两个相邻节点，并返回其头部。
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//fuction first
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;
		ListNode* tmp = head->next;
		head->next = swapPairs(tmp->next);
		tmp->next = head;
		return tmp;
	}

	//function second
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode* dummy = new ListNode(-1), *pre = dummy;
		dummy->next=head;
		while (pre->next&&pre->next->next)
		{
			ListNode* last = pre->next->next;
			pre->next->next = last->next;
			last->next = pre->next;
			pre->next = last;
			pre = last->next;
		}
		return dummy->next;
	}
};