/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	//function first
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		int val = head->val;
		ListNode* p = head->next;
		if (p->val != val)
		{
			head->next = deleteDuplicates(p);
			return head;
		}
		else {
			while (p&&p->val == val)
				p = p->next;
			return deleteDuplicates(p);
		}
	}

	//function second
	ListNode* deleteDuplicates2(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = dummy;
		int dup;
		while (cur->next&&cur->next->next) {
			if (cur->next->val == cur->next->next->val) {
				dup = cur->next->val;
				while (cur->next&&cur->next->val == dup)
					cur->next = cur->next->next;
			}
			else 
				cur = cur->next;
		}
		return dummy->next;
	}
};