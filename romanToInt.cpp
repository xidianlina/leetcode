/*
Roman to Integer
罗马数字转换为整数
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//function first
	int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> m{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
		for (int i = 0; i < s.size(); ++i) {
			int val = m[s[i]];
			if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]]) 
				res += val;
			else 
				res -= val;
		}
		return res;
	}

	//function second
	int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> m{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
		for (int i = 0; i < s.size(); ++i) {
			if (i == 0 || m[s[i]] <= m[s[i - 1]]) 
				res += m[s[i]];
			else 
				res += m[s[i]] - 2 * m[s[i - 1]];
		}
		return res;
	}
};