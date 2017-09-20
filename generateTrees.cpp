/*
Unique Binary Search Trees II
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.
1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
	vector<TreeNode*> buildTree(int start, int end) {
		vector<TreeNode*> trees;
		if (start > end) {
			trees.push_back(NULL);
			return trees;
		}
		if (start == end) {
			trees.push_back(new TreeNode(start));
			return trees;
		}
		for (int i = start; i <= end; i++) {
			//������iΪ�������������������п��ܡ�iȡֵstart��end
			vector<TreeNode*> leftTree = buildTree(start, i - 1);
			vector<TreeNode*> rightTree = buildTree(i + 1, end);
			//�������������п��ܺ������������п�������.leftTree[0]��ʾ��һ���ڵ㡣
			for (int j = 0; j < leftTree.size(); j++) {
				for (int k = 0; k < rightTree.size(); k++) {
					TreeNode* root = new TreeNode(i);
					root->left = leftTree[j];
					root->right = rightTree[k];
					//trees���浱ǰ�ĸ����
					trees.push_back(root);
				}
			}
		}
		return trees;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n == 0)
			return res;
		return buildTree(1, n);
	}
};