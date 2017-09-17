/*
Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
给定一个数组表示非负整数，其高位在数组的前面，对这个整数加1。
*/

#include <vector>

using namespace std;

class Solution {
public:
	//function first
	vector<int> plusOne(vector<int>& digits) {
		int n = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			int temp = digits[i] + n;
			digits[i] = temp % 10;
			n = temp / 10;
		}
		if (n == 1)
			digits.insert(digits.begin(), n);
		return digits;
	}

	//fuction second
	vector<int> plusOne2(vector<int> &digits)
	{
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] == 9)
				digits[i] = 0;
			else {
				++digits[i];
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};