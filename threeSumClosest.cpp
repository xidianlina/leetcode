/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.
三个数的和与target的差是否为最小
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		if (nums.empty()||len < 3)
			return 0;
		int closest = nums[0] + nums[1] + nums[2];
		int diff = abs(closest - target);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				int newDiff = abs(sum - target);
				if(diff > newDiff) {
					diff = newDiff;
					closest = sum;
				}
				if (sum < target)
					++j;
				else 
					--k;
			}
		}
		return closest;
	}
};