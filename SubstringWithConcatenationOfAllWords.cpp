/*
Substring with Concatenation of All Words
����һ��Ŀ���ַ���s��һ�����ʼ���words��
Ҫ��ʹ��words����������Ԫ������������s�е���λ����ɵļ��ϣ�Ԫ��˳�򲻿��ǣ���
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
		map<string, int> word_count;//��¼����words��ÿ�����ʵĳ��ִ���		
		int word_size = strlen(words[0].c_str());//ÿ�����ʵĳ�����ͬ
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
				string word = s.substr(i + j*word_size, word_size);//���鵱ǰ�����Ƿ�����words�Լ����ֵĴ����Ƿ�һ��
				if (word_count.find(word) != word_count.end())
				{
					++tmp_cnt[word];
					if (tmp_cnt[word] > word_count[word])//������ֵĴ�����words��һ�£��򷵻ش���
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