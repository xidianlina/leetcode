/*
Word Search
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
һ����ά��ĸ�����飬�������������ߣ������Ƿ�ĳ�������Ƿ���ڡ�ͬһλ�õ���ĸ�����Ա�ʹ�ö�Ρ�
*/
#include <vector>

using namespace std;

class Solution {
	bool searchDFS(int row, int col, string &word, int index, vector<vector<char>> &board)
	{
		if (index == word.size() - 1)
			return true;
		char ctmp = board[row][col];
		board[row][col] = '#';//��־Ϊ�ѷ���
		//��
		if (row - 1 >= 0 && board[row - 1][col] == word[index + 1])
			if (searchDFS(row - 1, col, word, index + 1, board))
				return true;
		//��
		if (row + 1 < board.size() && board[row + 1][col] == word[index + 1])
			if (searchDFS(row + 1, col, word, index + 1, board))
				return true;
		//��
		if (col - 1 >= 0 && board[row][col - 1] == word[index + 1])
			if (searchDFS(row, col - 1, word, index + 1, board))
				return true;
		//��
		if (col + 1 < board[0].size() && board[row][col + 1] == word[index + 1])
			if (searchDFS(row, col + 1, word, index + 1, board))
				return true;
		board[row][col] = ctmp;
		return false;
	}
public:
	bool exist(vector<vector<char>> &board, string word) {
		const int row = board.size();
		if (row == 0)
			return false;
		const int col = board[0].size();
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (board[i][j] == word[0] && searchDFS(i, j, word, 0, board))
					return true;
		return false;
	}
};