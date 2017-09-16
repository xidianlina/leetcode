/*
N-Queens
n�ʺ����⣬���������n��n�����У�ÿ�з�һ�����ӣ�ʹ���������ڵ��к�����б����û���������ӣ�ö�����п��ܡ�
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	/*function first
	����ⷨΪ���ݵݹ飬һ��һ�������ɨ�裬��Ҫ�õ�һ��pos���飬
	����pos[i]��ʾ��i�лʺ��λ�ã���ʼ��Ϊ-1��Ȼ��ӵ�0��ʼ�ݹ飬ÿһ�ж�һ�α������У�
	�ж�����ڸ�λ�÷��ûʺ�᲻���г�ͻ���Դ����ƣ��������һ�еĻʺ�źú�
	һ�ֽⷨ�������ˣ����������res�У�Ȼ���ٻ����������������е����
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

	// �������N-Queen����  
	// ��ÿһ���ϣ�����ÿһ�����ܵ��е�λ��  
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

		// ��  
		for (int i = 0; i <= row; i++)
		{
			if (cur[i][col] == 'Q')
				count++;
			if (count>1) 
				return false;
		}

		count = 0;

		//�ҶԽ���  
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		{
			if (cur[i][j] == 'Q')
				count++;
			if (count>1) 
				return false;
		}

		count = 0;

		//��Խ���  
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