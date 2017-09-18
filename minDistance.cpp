/*
Edit Distance
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int row = word1.length() + 1;
		int col = word2.length() + 1;
		vector < vector<int>> f(row, vector<int>(col));
		for (int i = 0; i < row; i++)
			f[i][0] = i;
		for (int i = 0; i < col; i++)
			f[0][i] = i;
		for(int i=1;i<row;i++)
			for (int j = 1; j < col; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					f[i][j] = f[i - 1][j - 1];
				else
					f[i][j] = f[i - 1][j - 1] + 1;
				f[i][j] = min(f[i][j], min(f[i - 1][j] + 1, f[i][j - 1] + 1));
			}
		return f[row - 1][col - 1];
	}
};