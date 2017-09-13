/*
Substring with Concatenation of All Words
给定一个目标字符串s，一个单词集合words。
要求使得words集合中所有元素连续出现在s中的首位置组成的集合（元素顺序不考虑）。
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.empty())
			return vector<int>();
		vector<int> res;		
		map<string, int> word_count;//记录所给words中每个单词的出现次数		
		int word_size = strlen(words[0].c_str());//每个单词的长度相同
		int word_nums = words.size();
		int s_len = strlen(s.c_str());
		for (int i = 0; i < word_nums; i++)
			++word_count[words[i]];
		int i, j;
		map<string, int> tmp_cnt;
		for (i = 0; i < s_len - word_nums*word_size + 1; i++)
		{
			tmp_cnt.clear();
			for (j = 0; j < word_nums; j++)
			{
				string word = s.substr(i + j*word_size, word_size);//检验当前单词是否属于words以及出现的次数是否一致
				if (word_count.find(word) != word_count.end())
				{
					++tmp_cnt[word];
					if (tmp_cnt[word] > word_count[word])//如果出现的次数与words不一致，则返回错误
						break;
				}
				else
					break;
			}
			if (j == word_nums)
				res.push_back(i);
		}
		return res;
	}
};