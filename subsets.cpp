/*
Subsets
Given a set of distinct integers, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
	[3],
	[1],
	[2],
	[1,2,3],
	[1,3],
	[2,3],
	[1,2],
	[]
]
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//function first
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>>  res(1);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			int size = res.size();
			for (int j = 0; j < size; j++)
			{
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}

	//function second
	vector<vector<int>> subsets2(vector<int> &nums)
	{
		vector<vector<int>> res;
		vector<int> out;
		sort(nums.begin(), nums.end());
		getSubsets(nums, 0, out, res);
		return res;
	}

private:
	void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res) {
		res.push_back(out);
		for (int i = pos; i<nums.size(); i++)
		{
			out.push_back(nums[i]);
			getSubsets(nums, i + 1, out, res);
			out.pop_back();
		}
	}
};