/*
Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
	[2,4],
	[3,4],
	[2,3],
	[1,2],
	[1,3],
	[1,4],
]
*/

#include <vector>

using namespace std;

class Solution {
	void helper(int n, int k, int level, vector<int> &out, vector<vector<int>> &res)
	{
		if (out.size() == k)
			res.push_back(out);
		for (int i = level; i <= n; i++)
		{
			out.push_back(i);
			helper(n, k, i + 1, out, res);
			out.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> out;
		helper(n, k, 1, out, res);
		return res;
	}
};