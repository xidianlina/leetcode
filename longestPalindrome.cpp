/*
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"
对于每个子串的中心（可以是一个字符，或者是两个字符的间隙，比如串abc,中心可以是a,b,c,
或者是ab的间隙，bc的间隙，例如aba是回文，abba也是回文，这两种情况要分情况考虑）往两边同时进行扫描，
直到不是回文串为止。假设字符串的长度为n,那么中心的个数为2*n-1(字符作为中心有n个，间隙有n-1个）。
对于每个中心往两边扫描的复杂度为O(n),所以时间复杂度为O((2*n-1)*n)=O(n^2),空间复杂度为O(1)。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestPalindrome(string s);
string longestPalindrome2(string s);
string helper(string, int, int);

//int main() {
//	string s;
//	cout << "enter a string: ";
//	cin >> s;
//	cout << longestPalindrome(s) << endl;
//	cout << longestPalindrome2(s) << endl;
//	return 0;
//}

string longestPalindrome2(string s) {
	if (s.empty() || s.length() == 1)
		return s;
	string longeststr = s.substr(0, 1);
	for (int i = 0; i < s.length(); i++) {
		string tmp = helper(s, i, i);
		if (tmp.length() > longeststr.length())
			longeststr = tmp;
		tmp = helper(s, i, i + 1);
		if (tmp.length() > longeststr.length())
			longeststr = tmp;
	}
	return longeststr;
}

string helper(string s, int begin, int end) {
	while (begin >= 0 && end <= s.length() - 1 && s[begin] == s[end]) {
		begin--;
		end++;
	}
	return s.substr(begin + 1, end-begin-1);
}

string longestPalindrome(string s) {
	vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));

	int max_len = 0;
	int index = 0;

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= i; j++) {
			if (s[i - 1] == s[j - 1] && (i - j < 2 || dp[j + 1][i - 1])) {
				if (i - j + 1 > max_len) {
					max_len = i - j + 1;
					index = j - 1;
				}
				dp[j][i] = true;
			}
		}
	}
	return s.substr(index, max_len);
}