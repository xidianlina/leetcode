/*
Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.size(), n2 = num2.size();
		vector<int> tmpres(n1 + n2, 0);
		int k = n1 + n2 - 2;
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < n2; j++)
				tmpres[k - i - j] += (num1[i] - '0')*(num2[j] - '0');
		int carryBit = 0;
		for (int i = 0; i < n1 + n2; i++)//处理进位
		{
			tmpres[i] += carryBit;
			carryBit = tmpres[i] / 10;
			tmpres[i] %= 10;
		}
		int i = k + 1;
		while (tmpres[i] == 0)
			i--;//去掉乘积的前导0
		if (i < 0)
			return "0"; //注意乘积为0的特殊情况
		string res;
		for (int i = 0; i < n1 + n2; i++)
			cout << tmpres[i] << " ";
		for (; i >= 0; i--)
			res.push_back(tmpres[i] + '0');
		return res;
	}
};

int main()
{
	Solution s;
	s.multiply("289","758");

	return 0;
}