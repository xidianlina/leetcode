/*
Maximal Rectangle
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int res = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> height(n + 1, 0);
		for (int i = 0; i < m; i++) {
			stack<int> stk;
			for (int j = 0; j < n + 1; j++) {
				if (j < n)
					height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
				while (!stk.empty() && height[stk.top()] >= height[j]) {
					int cur = stk.top();
					stk.pop();
					res = max(res, height[cur] * (stk.empty() ? j : (j - stk.top() - 1)));
				}
				stk.push(j);
			}
		}
		return res;
	}
};