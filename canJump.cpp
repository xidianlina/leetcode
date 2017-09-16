/*
Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//function first
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int reach = 1;
		for (int i = 0; i<reach&&reach<n; i++)
			reach = max(reach, i + 1 + nums[i]);
		return reach >= n;
	}

	//function second
	bool canJump2(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 0 || n == 1)
			return true;
		int maxStep = nums[0];
		for (int i = 1; i < n; i++)
		{
			if (maxStep == 0)
				return false;
			maxStep--;
			if (maxStep < nums[i])
				maxStep = nums[i];
			if (maxStep + i >= n - 1)
				return true;
		}
	}
};