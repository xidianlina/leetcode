/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.
题意分析：本题是将数字从1开始，将当前数字转化为口语对应的数字。
比如1口语是1个1，记作11；11读作2个1，记作21；21读作1个2，1个1，记作1211……
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0)
			return NULL;
		string res = "1";
		for (int i = 1; i < n; ++i) {
			string tmp;
			std::cout << res << std::endl;
			res.push_back('$');
			std::cout << res << std::endl;
			int count = 0;
			int len = strlen(res.c_str());
			for (int j = 0; j < len; ++j) {
				if (j == 0)
					++count;
				else {
					if (res[j] != res[j - 1]) {
						tmp.push_back(count + '0');
						tmp.push_back(res[j - 1]);
						count = 1;
					}
					else
						++count;
				}
			}
			res = tmp;
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.countAndSay(15);
}