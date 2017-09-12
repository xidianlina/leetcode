/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
��������n�����������У��������е�������a��b��cʹ��a + b + c = 0���ҳ����ظ�������
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num) {
		int digit = 0;//�������ĺ�  
		vector<vector<int>> result;
		int len = num.size();
		if (len < 3)
			return result;
		sort(num.begin(), num.end());
		for (int i = 0; i < len; i++)
		{
			//������ĿҪ�������ظ��ģ���������ǰ�������ϴε���ͬ�������  
			if (i > 0 && num[i] == num[i - 1])
				continue;
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				//ͬ��  
				if (k < len - 1 && num[k] == num[k + 1])
				{
					k--;
					continue;
				}
				//�����ǰ�������ͽ�С����j����ƶ���ʹ����������  
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
						vector<int> cur;//�������涨����԰��ϴ�ѭ����cur���ǵ�  
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