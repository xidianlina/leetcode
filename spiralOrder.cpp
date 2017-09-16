/*
Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty()) 
			return res;

		int row = matrix.size();
		int col = matrix[0].size();

		int rowBegin = 0;
		int rowEnd = row - 1;
		int colBegin = 0;
		int colEnd = col - 1;

		//螺旋曲线，运动轨迹总是一致的  
		while (rowBegin <= rowEnd && colBegin <= colEnd)
		{
			//向右列递增遍历  
			for (int j = colBegin; j <= colEnd; j++)
			{
				res.push_back(matrix[rowBegin][j]);
			}
			rowBegin++; //遍历后，去掉此行  

			//向下行递增遍历  
			for (int i = rowBegin; i <= rowEnd; i++)
			{
				res.push_back(matrix[i][colEnd]);
			}
			colEnd--;   //遍历后，去掉此列  

			if (rowBegin <= rowEnd)  //重要判断，防止重复  
			{
				//向左列递减遍历  
				for (int j = colEnd; j >= colBegin; j--)
				{
					res.push_back(matrix[rowEnd][j]);
				}

			}
			rowEnd--;   //遍历后，去掉此行  

			if (colBegin <= colEnd)  //重要判断，防止重复  
			{
				//向上行递减遍历  
				for (int i = rowEnd; i >= rowBegin; i--)
				{
					res.push_back(matrix[i][colBegin]);
				}
			}
			colBegin++; //遍历后，去掉此列  
		}
		return res;
	}
};