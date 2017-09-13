/*
Merge Two Sorted Lists
合并两个排好序的链表，并返回这个新链表。
新链表应该由这两个链表的头部拼接而成。
*/

#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	//fuction first
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		if (list1 == NULL)
			return list2;
		if (list2 == NULL)
			return list1;
		ListNode* head = NULL;
		if (list1->val < list2->val)
		{
			head = list1;
			head->next = mergeTwoLists(list1->next, list2);
		}
		else {
			head = list2;
			head->next = mergeTwoLists(list1, list2->next);
		}
		return head;
	}

	//function second
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* head = new ListNode(-1), *cur = head;
		while (list1&&list2)
		{
			if (list1->val < list2->val)
			{
				cur->next = list1;
				list1 = list1->next;
			}
			else {
				cur->next = list2;
				list2 = list2->next;
			}
			cur = cur->next;
		}
		cur->next = list1 ? list1 : list2;
		return head->next;
	}
};