/*
Interleaving String
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size();
		int n = s2.size();
		if (m + n != s3.size())
			return false;
		vector<vector<bool> > path(m + 1, vector<bool>(n + 1, false));
		for (int i = 0; i < m + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (i == 0 && j == 0)
					// start
					path[i][j] = true;
				else if (i == 0)
					path[i][j] = path[i][j - 1] & (s2[j - 1] == s3[j - 1]);
				else if (j == 0)
					path[i][j] = path[i - 1][j] & (s1[i - 1] == s3[i - 1]);
				else
					path[i][j] = (path[i][j - 1] & (s2[j - 1] == s3[i + j - 1])) || (path[i - 1][j] & (s1[i - 1] == s3[i + j - 1]));
			}
		}
		return path[m][n];
	}
};