/*
Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		if (t.size() > s.size())
			return "";
		string res = "";
		int left = 0;
		int count = 0;
		int minLen = s.size() + 1;
		unordered_map<char, int> m;
		for (int i = 0; i < t.size(); i++)
			if (m.find(t[i]) != m.end())
				++m[t[i]];
			else
				m[t[i]] = 1;
		for (int right = 0; right < s.size(); right++)
			if (m.find(s[right]) != m.end()) {
				--m[s[right]];
				if (m[s[right]] >= 0)
					++count;
				while (count == t.size())
				{
					if (right - left + 1 < minLen)
					{
						minLen = right - left + 1;
						res = s.substr(left, minLen);
					}
					if (m.find(s[left]) != m.end())
					{
						++m[s[left]];
						if (m[s[left]] > 0)
							--count;
					}
					++left;
				}
			}
		return res;
	}
};