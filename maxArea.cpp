/*
Container With Most Water
给定n个非负整数a1,a2,...,an，其中每个代表一个点坐标（i,ai）。
n个垂直线段例如线段的两个端点在（i,ai）和（i,0）。
找到两个线段，与x轴形成一个容器，使其包含最多的水。
题目的意思是，数组中的每个数对应一条线段的长度，索引对应x坐标，两个索引可以组成一个底部的宽，
高度就是前面所说的线段的长度，而既然是要盛水，高度就是两个线段中较短的一个。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
			return 0;
		int res = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			int volumn = (right - left)*min(height[right] , height[left]);
			if (volumn > res)
				res = volumn;
			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return res;
	}
};