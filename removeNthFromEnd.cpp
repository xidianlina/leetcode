/*
Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
移除链表倒数第N个节点，限定n一定是有效的，即n不会大于链表中的元素总数,要求一次遍历解决问题
*/

#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == NULL)
			return NULL;
		ListNode* pre = head, *cur = head;
		for (int i = 0; i < n; i++)
			cur = cur->next;
		if (cur == NULL)
			return head->next;
		while (cur->next)
		{
			cur = cur->next;
			pre = pre->next;
		}
		pre->next = pre->next->next;
		return head;
	}
};