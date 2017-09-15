/*
Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	//function first
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		set<vector<int>> res;
		permute(nums, 0, res);
		return vector<vector<int>>(res.begin(), res.end());
	}
	void permute(vector<int> &nums, int start, set<vector<int>> &res) {
		if (start >= nums.size()) res.insert(nums);
		for (int i = start; i < nums.size(); ++i) {
			if (i != start && nums[i] == nums[start]) continue;
			swap(nums[i], nums[start]);
			permute(nums, start + 1, res);
			swap(nums[i], nums[start]);
		}
	}

	//function second
	vector<vector<int> > permuteUnique2(vector<int> &num) {
		vector<vector<int> > res;
		vector<int> out;
		vector<int> visited(num.size(), 0);
		sort(num.begin(), num.end());
		permuteUniqueDFS2(num, 0, visited, out, res);
		return res;
	}
	void permuteUniqueDFS2(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
		if (level >= num.size()) res.push_back(out);
		else {
			for (int i = 0; i < num.size(); ++i) {
				if (visited[i] == 0) {
					if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) continue;
					visited[i] = 1;
					out.push_back(num[i]);
					permuteUniqueDFS2(num, level + 1, visited, out, res);
					out.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
};