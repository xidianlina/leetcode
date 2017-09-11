/*
Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true
*/

#include <iostream>
#include <string>

using namespace std;

/*
���˼·���£�
��pΪ�գ���sҲΪ�գ�����true����֮����false
��p�ĳ���Ϊ1����s����ҲΪ1������ͬ����pΪ'.'�򷵻�true����֮����false
��p�ĵڶ����ַ���Ϊ*������ʱsΪ�շ���false�������ж����ַ��Ƿ�ƥ�䣬�ҴӸ��Եĵڶ����ַ���ʼ���õݹ麯��ƥ��
��p�ĵڶ����ַ�Ϊ*����s��Ϊ�����ַ�ƥ�䣬���õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p����ƥ�䷵��true������sȥ������ĸ
���ص��õݹ麯��ƥ��s��ȥ��ǰ�����ַ���p�Ľ��
*/
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) 
			return s.empty();
		if (p.size() == 1) {
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
		}
		if (p[1] != '*') {
			if (s.empty()) 
				return false;
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2))) 
				return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};