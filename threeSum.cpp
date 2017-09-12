/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
给定含有n个整数的数列，求数列中的三个数a，b，c使得a + b + c = 0，找出不重复的数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num) {
		int digit = 0;//三个数的和  
		vector<vector<int>> result;
		int len = num.size();
		if (len < 3)
			return result;
		sort(num.begin(), num.end());
		for (int i = 0; i < len; i++)
		{
			//由于题目要求不能有重复的，因此如果当前的数和上次的相同，则忽略  
			if (i > 0 && num[i] == num[i - 1])
				continue;
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				//同上  
				if (k < len - 1 && num[k] == num[k + 1])
				{
					k--;
					continue;
				}
				//如果当前三个数和较小，则j向后移动，使得总数增大  
				if (num[j] + num[k] + num[i] < digit)
				{
					j++;
				}
				else
				{
					if (num[j] + num[k] + num[i] > digit)
					{
						k--;
					}
					else
					{
						vector<int> cur;//在这里面定义可以把上次循环的cur覆盖掉  
						cur.push_back(num[i]);
						cur.push_back(num[j]);
						cur.push_back(num[k]);
						result.push_back(cur);
						j++;
						k--;
					}

				}
			}
		}
		return result;
	}
};