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
	需要注意几个细节：
    1.重复连续出现的'/'，只按1个处理，即跳过重复连续出现的'/'；
    2.如果路径名是"."，则不处理；
    3.如果路径名是".."，则需要弹栈，如果栈为空，则不做处理；
    4.如果路径名为其他字符串，入栈。
	最后，再逐个取出栈中元素（即已保存的路径名），用'/'分隔并连接起来，不过要注意顺序。
	*/
	string simplifyPath(string path) {
		stack<string> stack;
		int i = 0;
		while (i < path.size()) {
			// 跳过斜线'/'
			while (i < path.size() && '/' == path[i])
				++i;
			// 记录路径名
			string s = "";
			while (i < path.size() && path[i] != '/')
				s += path[i++];
			// 如果是".."则需要弹栈，否则入栈
			if (".." == s && !stack.empty())
				stack.pop();
			else if ("" != s&&s != "."&&s != "..")
				stack.push(s);
		}
		// 如果栈为空，说明为根目录，只有斜线'/'
		if (stack.empty())
			return "/";
		// 逐个连接栈里的路径名
		string s = "";
		while (!stack.empty())
		{
			s = "/" + stack.top() + s;
			stack.pop();
		}
		return s;
	}
};