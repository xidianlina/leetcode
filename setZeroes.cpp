/*
Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
给定一个矩阵，如果有零元素那么就将零元素所在的行和列都置为零。
*/

#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		vector<bool> row(m, false);
		vector<bool> col(n, false);
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				if (0 == matrix[i][j])
					row[i] = col[j] = true;//如果原矩阵中存在0，记录该行和列的位置。
		for (size_t i = 0; i < m; i++)
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n, 0);//将矩阵的一行置为0
		for (size_t j = 0; j < n; j++)
			if (col[j])
				for (size_t i = 0; i < m; i++)
					matrix[i][j] = 0;//将矩阵的一列置为0
	}
};