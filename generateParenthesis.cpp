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
给定一个非负整数n，生成n对括号的所有合法排列。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	function first
	定义两个变量left和right分别表示剩余左右括号的个数，如果在某次递归时，
	左括号的个数大于右括号的个数，说明此时生成的字符串中右括号的个数大于左括号的个数，
	即会出现')('这样的非法串，所以这种情况直接返回，不继续处理。
	如果left和right都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，
	则存入结果中后返回。如果以上两种情况都不满足，若此时left大于0，则调用递归函数，
	注意参数的更新，若right大于0，则调用递归函数，同样要更新参数。
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
	找左括号，每找到一个左括号，就在其后面加一个完整的括号，最后再在开头加一个()，就形成了所有的情况，
	需要注意的是，有时候会出现重复的情况，所以我们用set数据结构，好处是如果遇到重复项，
	不会加入到结果中，最后我们再把set转为vector即可
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