/*
Unique Paths II
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
*/

#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<int> res(n, 0);
		res[0] = 1;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					res[j] = 0;
				else
				{
					if (j != 0)
						res[j] += res[j - 1];
				}

			}
		}
		return res[n - 1];
	}
};