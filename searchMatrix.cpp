/*
Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:
[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		if (target<matrix[0][0] || target>matrix.back().back())
			return false;
		int left = 0;
		int right = matrix.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		int tmp = right;
		left = 0;
		right = matrix[tmp].size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (matrix[tmp][mid] == target)
				return true;
			else if (matrix[tmp][mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return false;
	}
};