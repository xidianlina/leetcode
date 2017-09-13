/*
Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
����һ���Ǹ�����n������n�����ŵ����кϷ����С�
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	function first
	������������left��right�ֱ��ʾʣ���������ŵĸ����������ĳ�εݹ�ʱ��
	�����ŵĸ������������ŵĸ�����˵����ʱ���ɵ��ַ����������ŵĸ������������ŵĸ�����
	�������')('�����ķǷ����������������ֱ�ӷ��أ�����������
	���left��right��Ϊ0����˵����ʱ���ɵ��ַ�������3�������ź�3�������ţ����ַ����Ϸ���
	��������к󷵻ء����������������������㣬����ʱleft����0������õݹ麯����
	ע������ĸ��£���right����0������õݹ麯����ͬ��Ҫ���²�����
	*/
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generateParenthesisDFS(n, n, "", res);
		return res;
	}

	void generateParenthesisDFS(int left, int right, string out, vector<string> &res)
	{
		if (left > right)
			return;
		if (left == 0 && right == 0)
			res.push_back(out);
		else {
			if (left > 0)
				generateParenthesisDFS(left - 1, right, out + '(', res);
			if (right > 0)
				generateParenthesisDFS(left, right - 1, out + ')', res);
		}
	}

	/*
	function second
	�������ţ�ÿ�ҵ�һ�������ţ�����������һ�����������ţ�������ڿ�ͷ��һ��()�����γ������е������
	��Ҫע����ǣ���ʱ�������ظ������������������set���ݽṹ���ô�����������ظ��
	������뵽����У���������ٰ�setתΪvector����
	*/
	vector<string> generateParenthesis(int n) {
		set<string> t;
		if (n == 0)
			t.insert("");
		else {
			vector<string> pre = generateParenthesis(n - 1);
			for (auto a : pre) {
				for (int i = 0; i < a.size(); ++i) {
					if (a[i] == '(') {
						a.insert(a.begin() + i + 1, '(');
						a.insert(a.begin() + i + 2, ')');
						t.insert(a);
						a.erase(a.begin() + i + 1, a.begin() + i + 3);
					}
				}
				t.insert("()" + a);
			}
		}
		return vector<string>(t.begin(), t.end());
	}
};