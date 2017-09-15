/*
Given a collection of distinct numbers, return all possible permutations.
È«ÅÅÁÐ
*/

#include <vector>

using namespace std;

class Solution {
public:
	//function first
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		permuteDFS(num, 0, res);
		return res;
	}
	void permuteDFS(vector<int> &num, int start, vector<vector<int> > &res) {
		if (start >= num.size()) res.push_back(num);
		for (int i = start; i < num.size(); ++i) {
			swap(num[start], num[i]);
			permuteDFS(num, start + 1, res);
			swap(num[start], num[i]);
		}
	}

	//function second
	vector<vector<int> > permute2(vector<int> &num) {
		vector<vector<int> > res;
		vector<int> out;
		vector<int> visited(num.size(), 0);
		permuteDFS2(num, 0, visited, out, res);
		return res;
	}
	void permuteDFS2(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
		if (level == num.size()) res.push_back(out);
		else {
			for (int i = 0; i < num.size(); ++i) {
				if (visited[i] == 0) {
					visited[i] = 1;
					out.push_back(num[i]);
					permuteDFS2(num, level + 1, visited, out, res);
					out.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
};