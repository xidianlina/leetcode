/*
Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
合并K个排序链表
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size();
		if (len == 0)
			return NULL;
		while (len > 1)
		{
			int k = (len + 1) / 2;
			for (int i = 0; i < len / 2; i++)
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			len = k;
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		while (list1&&list2)
		{
			if (list1->val < list2->val)
			{
				cur->next = list1;
				list1 = list1->next;
			}
			else
			{
				cur->next = list2;
				list2 = list2->next;
			}
			cur = cur->next;
		}
		if (list1)
			cur->next = list1;
		if (list2)
			cur->next = list2;
		return head->next;
	}
};