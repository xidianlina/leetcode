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
��������һ���ַ������飬����ͬ���ʣ���ͬ��ĸ��ɵĵ��ʣ����࣬ÿ�鵥�ʰ����ֵ�����
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
		//���ַ������鰴���ֵ�˳������
		sort(strs.begin(), strs.end());
		//�洢���
		vector<vector<string> > ret;
		//���ù�ϣ˼�빹��map�����������ȵ��ַ���������Ӧ��vector
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