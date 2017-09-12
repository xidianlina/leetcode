/*
four sum
Given an array S of n integers, are there elements a, b, c, 
and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//funciton first
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		set<vector<int>> res;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i<len - 3; i++)
		{
			for (int j = i + 1; j < len - 2; j++)
			{
				int left = j + 1;
				int right = len - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target)
					{
						vector<int> out;
						out.push_back(nums[i]);
						out.push_back(nums[j]);
						out.push_back(nums[left]);
						out.push_back(nums[right]);
						res.insert(out);
						left++;
						right--;
					}
					else if (sum > target)
					{
						right--;
					}
					else {
						left++;
					}
				}
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
	}

	//function second
	vector<vector<int>> fourSum2(vector<int> &nums, int target)
	{
		vector<vector<int>> res;
		int len = nums.size();
		if (len < 4)
			return res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			if (nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target)
				continue;
			for (int j = i + 1; j < len - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				if (nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target)
					continue;
				int left = j + 1;
				int right = len - 1;
				while (left<right) {
					int sum = nums[left] + nums[right] + nums[i] + nums[j];
					if (sum<target)
						left++;
					else if (sum>target)
						right--;
					else {
						res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						do { left++; } 
						while (nums[left] == nums[left - 1] && left<right);
						do { right--; } 
						while (nums[right] == nums[right + 1] && left<right);
					}
				}
			}
		}
		return res;
	}
};