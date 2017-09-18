/*
Simplify Path
Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	/*
	��Ҫע�⼸��ϸ�ڣ�
    1.�ظ��������ֵ�'/'��ֻ��1�������������ظ��������ֵ�'/'��
    2.���·������"."���򲻴���
    3.���·������".."������Ҫ��ջ�����ջΪ�գ���������
    4.���·����Ϊ�����ַ�������ջ��
	��������ȡ��ջ��Ԫ�أ����ѱ����·����������'/'�ָ�����������������Ҫע��˳��
	*/
	string simplifyPath(string path) {
		stack<string> stack;
		int i = 0;
		while (i < path.size()) {
			// ����б��'/'
			while (i < path.size() && '/' == path[i])
				++i;
			// ��¼·����
			string s = "";
			while (i < path.size() && path[i] != '/')
				s += path[i++];
			// �����".."����Ҫ��ջ��������ջ
			if (".." == s && !stack.empty())
				stack.pop();
			else if ("" != s&&s != "."&&s != "..")
				stack.push(s);
		}
		// ���ջΪ�գ�˵��Ϊ��Ŀ¼��ֻ��б��'/'
		if (stack.empty())
			return "/";
		// �������ջ���·����
		string s = "";
		while (!stack.empty())
		{
			s = "/" + stack.top() + s;
			stack.pop();
		}
		return s;
	}
};