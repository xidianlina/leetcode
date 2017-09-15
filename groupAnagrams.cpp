/*
Group Anagrams
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
将给定的一组字符串数组，按照同构词（相同字母组成的单词）分类，每组单词按照字典排序。
*/

#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.empty())
			return vector<vector<string> >();
		int len = strs.size();
		//将字符串数组按照字典顺序排序
		sort(strs.begin(), strs.end());
		//存储结果
		vector<vector<string> > ret;
		//利用哈希思想构建map，将排序后相等的字符串存在相应的vector
		map<string, vector<string>> mv;
		for (int i = 0; i < len; i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());

			mv[str].push_back(strs[i]);
		}

		for (map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)
			ret.push_back(iter->second);

		return ret;
	}
};