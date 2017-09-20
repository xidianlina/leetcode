/*
Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
  2
 / \
1   3
Binary tree [2,1,3], return true.
Example 2:
  1
 / \
2   3
Binary tree [1,2,3], return false.
*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode *root, long mn, long mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;
		return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
	}
};