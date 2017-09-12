/*
Letter Combinations of a Phone Number
电话号码的字母组合
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	//function first 递归
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty()) 
			return res;
		string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		letterCombinationsDFS(digits, dict, 0, "", res);
		return res;
	}
	void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
		if (level == digits.size()) 
			res.push_back(out);
		else {
			string str = dict[digits[level] - '2'];
			for (int i = 0; i < str.size(); ++i) {
				out.push_back(str[i]);
				letterCombinationsDFS(digits, dict, level + 1, out, res);
				out.pop_back();
			}
		}
	}
	
	//function second 迭代
	vector<string> letterCombinations2(string digits) {
		vector<string> res;
		if (digits.empty())
			return res;
		string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		res.push_back("");
		for (int i = 0; i < digits.size(); ++i) {
			int n = res.size();
			string str = dict[digits[i] - '2'];
			for (int j = 0; j < n; ++j) {
				string tmp = res.front();
				res.erase(res.begin());
				for (int k = 0; k < str.size(); ++k) {
					res.push_back(tmp + str[k]);
				}
			}
		}
		return res;
	}
};