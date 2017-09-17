/*
Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/

#include <vector>

using namespace std;

class Solution {
public:
	//function first
	int uniquePaths(int m, int n) {
		vector<vector<int>> v(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				v[i][j] = v[i - 1][j] + v[i][j - 1];
		return v[m - 1][n - 1];
	}

	//function second
	int uniquePaths2(int m, int n)
	{
		vector<int> v(n, 1);
		for (int i = 1; i<m; ++i) {
			for (int j = 1; j<n; ++j) {
				v[j] += v[j - 1];
			}
		}
		return v[n - 1];
	}
};