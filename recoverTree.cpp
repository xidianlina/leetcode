/*
Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//function first
	void recoverTree(TreeNode *root) {
		vector<TreeNode*> list;
		vector<int> vals;
		inorder(root, list, vals);
		sort(vals.begin(), vals.end());
		for (int i = 0; i < list.size(); ++i) {
			list[i]->val = vals[i];
		}
	}
	void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
		if (!root)
			return;
		inorder(root->left, list, vals);
		list.push_back(root);
		vals.push_back(root->val);
		inorder(root->right, list, vals);
	}

	//function second
	void recoverTree(TreeNode *root) {
		TreeNode *first = NULL, *second = NULL, *parent = NULL;
		TreeNode *cur, *pre;
		cur = root;
		while (cur) {
			if (!cur->left) {
				if (parent && parent->val > cur->val) {
					if (!first) first = parent;
					second = cur;
				}
				parent = cur;
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
					if (parent->val > cur->val) {
						if (!first) first = parent;
						second = cur;
					}
					parent = cur;
					cur = cur->right;
				}
			}
		}
		if (first && second) swap(first->val, second->val);
	}
};