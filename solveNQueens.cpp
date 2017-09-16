/*
N-Queens
n皇后问题，题意就是求n×n矩阵中，每行放一个棋子，使得棋子所在的列和两条斜线上没有其他棋子，枚举所有可能。
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	/*function first
	经典解法为回溯递归，一层一层的向下扫描，需要用到一个pos数组，
	其中pos[i]表示第i行皇后的位置，初始化为-1，然后从第0开始递归，每一行都一次遍历各列，
	判断如果在该位置放置皇后会不会有冲突，以此类推，当到最后一行的皇后放好后，
	一种解法就生成了，将其存入结果res中，然后再还会继续完成搜索所有的情况
	*/
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > res;
		vector<int> pos(n, -1);
		solveNQueensDFS(pos, 0, res);
		return res;
	}
	void solveNQueensDFS(vector<int> &pos, int row, vector<vector<string> > &res) {
		int n = pos.size();
		if (row == n) {
			vector<string> out(n, string(n, '.'));
			for (int i = 0; i < n; ++i) {
				out[i][pos[i]] = 'Q';
			}
			res.push_back(out);
		}
		else {
			for (int col = 0; col < n; ++col) {
				if (isValid(pos, row, col)) {
					pos[row] = col;
					solveNQueensDFS(pos, row + 1, res);
					pos[row] = -1;
				}
			}
		}
	}
	bool isValid(vector<int> &pos, int row, int col) {
		for (int i = 0; i < row; ++i) {
			if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
				return false;
			}
		}
		return true;
	}
	//function second
	vector<vector<string> > solveNQueens(int n) {
		vector<string> out;
		vector<vector<string>> res;
		solveNQueensUtil(n, 0, out, res);

		return res;
	}

	// 逐行求解N-Queen问题  
	// 在每一行上，尝试每一个可能的列的位置  
	void solveNQueensUtil(int n, int row, vector<string> sol, vector<vector<string>>& res) {

		if (row == n)
		{
			res.push_back(sol);
			return;
		}

		for (int i = 0; i<n; i++)
		{
			string str(n, '.');
			str[i] = 'Q';
			sol.push_back(str);

			if (isValid(sol, row, i))
				solveNQueensUtil(n, row + 1, sol, res);

			sol.pop_back();
		}

	}

	bool isValid(vector<string> &cur, int row, int col)
	{
		int count = 0;

		// 列  
		for (int i = 0; i <= row; i++)
		{
			if (cur[i][col] == 'Q')
				count++;
			if (count>1) 
				return false;
		}

		count = 0;

		//右对角线  
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		{
			if (cur[i][j] == 'Q')
				count++;
			if (count>1) 
				return false;
		}

		count = 0;

		//左对角线  
		for (int i = row, j = col; i >= 0 && j < cur[0].size(); i--, j++)
		{
			if (cur[i][j] == 'Q')
				count++;
			if (count>1) 
				return false;
		}
		return true;
	}
};