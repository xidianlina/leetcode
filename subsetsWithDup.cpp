/*
Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[
	[2],
	[1],
	[1,2,2],
	[2,2],
	[1,2],
	[]
]
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.empty())
			return {};
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());
		int size = 1, last = nums[0];
		for (int i = 0; i < nums.size(); ++i) {
			if (last != nums[i]) {
				last = nums[i];
				size = res.size();
			}
			int newSize = res.size();
			for (int j = newSize - size; j < newSize; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}
};