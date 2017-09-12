/*
Longest Common Prefix
�������ַ����������ǰ׺��������������ַ������������ǰ׺��
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//function first ����ַ��Ƚϣ�ʱ�临�Ӷ�ΪO(N*L),N���ַ���������L���ǰ׺�ĳ���
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		string res;
		if (n == 0)return res;
		for (int pos = 0; pos < strs[0].size(); pos++)//�ǰ׺�ĳ��Ȳ�����strs[0].size()������ַ��ıȽ�
		{
			for (int k = 1; k < n; k++)//strs[0]�ĵ�pos���ַ��ֱ��strs[1...n-1]�ĵ�pos���ַ��Ƚ�
			{
				if (strs[k].size() == pos || strs[k][pos] != strs[0][pos])
					return res;
			}
			res.push_back(strs[0][pos]);
		}
		return res;
	}

	//function second
	//��0���ַ����������ַ��������ǰ׺ ,�����ַ������ǰ׺���� = min{ prefixLength(strs[0], strs[i]),0 < i < n }
	//ʱ�临�Ӷ���O(N*M),N���ַ���������M = strs[0]�������ַ�����ǰ׺���ȵ�ƽ��ֵ, �㷨2���ַ��ıȽϴ���Ҫ���㷨1�ࡣ
	string longestCommonPrefix2(vector<string>& strs) {
		int n = strs.size();
		if (n == 0)
			return "";
		int len = strs[0].size();//�ǰ׺�ĳ���
		for (int i = 1; i < n; i++)
		{
			int k;
			for (k = 0; k < min(len, (int)strs[i].size()); k++)
				if (strs[0][k] != strs[i][k])
					break;
			if (len > k)
				len = k;
		}
		return strs[0].substr(0, len);
	}
};