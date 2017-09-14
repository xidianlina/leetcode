/*
Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int res = 0, start = 0;
		stack<int> stack;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				stack.push(i);
			else if (s[i] == ')')
			{
				if (stack.empty())
					start = i + 1;
				else {
					stack.pop();
					res = stack.empty() ? max(res, i - start + 1) : max(res, i - stack.top());
				}
			}
		}
		return res;
	}
};