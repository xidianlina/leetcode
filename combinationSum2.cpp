/*
Combination Sum II
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> out;
		sort(candidates.begin(), candidates.end());
		combinationSumDFS2(candidates, target, 0, out, res);
		return res;
	}

	void combinationSumDFS2(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int>> &res)
	{
		if (target < 0)
			return;
		else if (target == 0)
			res.push_back(out);
		else {
			for (int i = start; i < candidates.size(); i++)
			{
				if (i > start&&candidates[i] == candidates[i - 1])
					continue;
				out.push_back(candidates[i]);
				combinationSumDFS2(candidates, target - candidates[i], i + 1, out, res);
				out.pop_back();
			}
		}
	}
};