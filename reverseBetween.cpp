/*
Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = dummy;
		ListNode* pre, *front, *last;
		for (int i = 1; i <= m - 1; i++)
			cur = cur->next;
		pre = cur;
		last = cur->next;
		for (int i = m; i <= n; i++) {
			cur = pre->next;
			pre->next = cur->next;
			cur->next = front;
			front = cur;
		}
		cur = pre->next;
		pre->next = front;
		last->next = cur;
		return dummy->next;
	}
};