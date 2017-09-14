/*
Valid Sudoku
Determine if a Sudoku is valid
依次检查每行，每列，每个子九宫格是否出现重复元素，如果出现返回false，否则返回true.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++)
		{
			unordered_map<char, bool> m1;   //check i_th row
			unordered_map<char, bool> m2;   //check i_th column
			unordered_map<char, bool> m3;   //check i_th subgrid
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					if (m1[board[i][j]] == true)
						return false;
					m1[board[i][j]] = true;
				}
				if (board[j][i] != '.')
				{
					if (m2[board[j][i]] == true)
						return false;
					m2[board[j][i]] = true;
				}
				if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.')
				{
					if (m3[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]] == true)
						return false;
					m3[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]] = true;
				}
			}
		}
		return true;
	}
};