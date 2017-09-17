/*
Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
将倒数K个节点放在链表前。
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
			return NULL;
		int len = 0;
		ListNode* cur = head;
		while (cur)
		{
			len++;
			cur = cur->next;
		}
		k %= len;
		ListNode *fast = head, *slow = head;
		for (int i = 0; i < k; i++)
			if (fast)
				fast = fast->next;
		if (!fast)
			return head;
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		fast->next = head;
		fast = slow->next;
		slow->next = NULL;
		return fast;
	}
};