/*
Implement strStr()
Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
实现strstr(). 返回needle(关键字)在haystack(字符串)中第一次出现的位置，如果needle不在haystack中，则返回-1。
注：strstr()是c++中的一个函数
*/

#include <string>

using namespace std;

class Solution {
public:
	/*
	对原串的每一个长度为m的字串都判断是否跟匹配串一致。总共有n-m+1个子串，
	所以算法时间复杂度为O((n-m+1)*m)=O(n*m)，空间复杂度是O(1)。
	*/
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		int m = haystack.size(), n = needle.size();
		if (m < n)
			return -1;
		for (int i = 0; i <= m - n; i++)
		{
			int j;
			for (j = 0; j < n; j++)
				if (haystack[i + j] != needle[j])
					break;
			if (j == n)
				return i;
		}
		return -1;
	}
};