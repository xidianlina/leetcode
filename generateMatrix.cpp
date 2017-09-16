/*
Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3,
You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0) 
			return vector<vector<int>>();
		vector<vector<int>> res(n, vector<int>(n, 0));

		int rowBegin = 0;
		int rowEnd = n - 1;
		int colBegin = 0;
		int colEnd = n - 1;
		int num = 1;

		while (rowBegin <= rowEnd && colBegin <= colEnd)
		{
			if (num <= n ^ 2)
			{
				//向右遍历添加
				for (int j = colBegin; j <= colEnd; j++)
				{
					res[rowBegin][j] = num;
					num++;
				}
			}
			rowBegin++;

			if (num <= n ^ 2)
			{
				//向下遍历添加
				for (int i = rowBegin; i <= rowEnd; i++)
				{
					res[i][colEnd] = num;
					num++;
				}
			}
			colEnd--;

			if (num <= n ^ 2)
			{
				//向左遍历添加
				for (int j = colEnd; j >= colBegin; j--)
				{
					res[rowEnd][j] = num;
					num++;
				}
			}
			rowEnd--;

			if (num <= n ^ 2)
			{
				//向上遍历添加
				for (int i = rowEnd; i >= rowBegin; i--)
				{
					res[i][colBegin] = num;
					num++;
				}
			}
			colBegin++;
		}
		return res;
	}
};