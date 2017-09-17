/*
Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		vector<vector<int>> res(grid);
		int i, j;
		for (int j = 1; j<res[0].size(); ++j) {
			res[0][j] += res[0][j - 1];
		}
		for (int j = 1; j<res.size(); ++j) {
			res[j][0] += res[j - 1][0];
		}
		for (i = 1; i<res.size(); ++i) {
			for (int j = 1; j<res[i].size(); ++j) {
				res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
			}
		}
		return res[grid.size() - 1][grid[0].size() - 1];
	}
};