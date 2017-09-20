/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	//function first
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())
			return 0;
		int maxArea = 0;
		int len = heights.size();
		for (int i = 0; i < len; ++i)
		{
			/*记录包含第i个柱体的矩形面积*/
			int tmpArea = heights[i];
			int left = i - 1, right = i + 1;
			/*左侧扩展*/
			while (left >= 0 && heights[left] >= heights[i])
			{
				tmpArea += heights[i];
				--left;
			}//while
			 /*右侧扩展*/
			while (right < len && heights[right] >= heights[i])
			{
				tmpArea += heights[i];
				++right;
			}

			if (maxArea < tmpArea)
				maxArea = tmpArea;
		}
		return maxArea;
	}

	//function second
	int largestRectangleArea(vector<int> &heights) {
		int res = 0;
		stack<int> stk;
		height.push_back(0);
		for (int i = 0; i<height.size(); ++i)
		{
			if (stk.empty() || height[stk.top()] <= height[i])
				stk.push(i);
			else
			{
				int temp = stk.top();
				stk.pop();
				res = max(res, height[temp] * (stk.empty() ? i : (i - stk.top() - 1)));
				--i;
			}
		}
		return res;
	}

	//function third
	int largestRectangleArea(vector<int> &height)
	{
		int res = 0;
		for (int i = 0; i < height.size(); ++i) {
			if (i + 1 < height.size() && height[i] <= height[i + 1]) {
				continue;
			}
			int minH = height[i];
			for (int j = i; j >= 0; --j) {
				minH = min(minH, height[j]);
				int area = minH * (i - j + 1);
				res = max(res, area);
			}
		}
		return res;
	}
};