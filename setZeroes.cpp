/*
Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
����һ�������������Ԫ����ô�ͽ���Ԫ�����ڵ��к��ж���Ϊ�㡣
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
					row[i] = col[j] = true;//���ԭ�����д���0����¼���к��е�λ�á�
		for (size_t i = 0; i < m; i++)
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n, 0);//�������һ����Ϊ0
		for (size_t j = 0; j < n; j++)
			if (col[j])
				for (size_t i = 0; i < m; i++)
					matrix[i][j] = 0;//�������һ����Ϊ0
	}
};