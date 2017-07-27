/*
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
//#include <iostream>
//
//struct ListNode {
//	int val;
//	ListNode*next;
//	ListNode(int x):val(x),next(NULL){}
//};
//
//class Solution {
//public:
//	ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode *head = NULL, *prev = NULL;
//		int carry = 0;
//		while (l1 || l2) {
//			int v1 = l1 ? l1->val : 0;
//			int v2 = l2 ? l2->val : 0;
//			int tmp = v1 + v2 + carry;
//			carry = tmp / 10;
//			int val = tmp % 10;
//			ListNode*cur = new ListNode(val);
//			if (!head)
//				head = cur;
//			if (prev)
//				prev->next = cur;
//			prev = cur;
//			l1 = l1 ? l1->next : NULL;
//			l2 = l2 ? l2->next : NULL;
//		}
//		if (carry>0) {
//			ListNode* l = new ListNode(carry);
//			prev->next = l;
//		}
//		return head;
//	}
//};
//
//int main()
//{
//	ListNode *l1 = new ListNode(2);
//	ListNode *l11 = new ListNode(4);
//	l1->next = l11;
//	ListNode *l12 = new ListNode(3);
//	l11->next = l12;
//	ListNode *l2 = new ListNode(5);
//	ListNode *l21 = new ListNode(6);
//	l2->next = l21;
//	ListNode *l22 = new ListNode(4);
//	l21->next = l22;
//	Solution fun;
//	ListNode *head = fun.addTwoNumbers(l1, l2);
//	while (head) {
//		std::cout << head->val << "\t";
//		head = head->next;
//	}
//	std::cout << std::endl;
//
//	return 0;
//}