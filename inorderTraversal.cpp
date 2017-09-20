/*
Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree [1,null,2,3],

1
  \
   2
  /
 3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
非递归中序遍历二叉树
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	//function first
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		if (!root) return res;
		TreeNode *cur, *pre;
		cur = root;
		while (cur) {
			if (!cur->left) {
				res.push_back(cur->val);
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right && pre->right != cur) pre = pre->right;
				if (!pre->right) {
					pre->right = cur;
					cur = cur->left;
				}
				else {
					pre->right = NULL;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return res;
	}
	//function second
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		stack<TreeNode*> stk;
		while (root || !stk.empty()) {
			if (root) {
				stk.push(root);
				root = root->left;
			}
			else {
				root = stk.top();
				res.push_back(root->val);
				stk.pop();
				root = root->right;
			}
		}
		return res;
	}
};