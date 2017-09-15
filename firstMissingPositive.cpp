/*
First Missing Positive
Given an unsorted integer array, find the first missing positive integer.
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.
给定一个数组，找出第一个缺失的正数，要求时间复杂度为O(n)，空间复杂度为O(1)。
*/

#include <vector>

using namespace std;

class Solution {
public:
	/*
	把正数n放在第n-1个位置上，这样从第一个位置开始，如果位置上的数不等于位置号，
	那么就是第一个缺失的正数
	*/
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		if (nums.empty() || n < 1)
			return 1;
		for (int i = 0; i < n; i++)
		{
			while (nums[i] > 0 && nums[i] <= n&&nums[nums[i] - 1] != nums[i])
			{
				int tmp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = tmp;
			}
		}
		for (int i = 0; i < n; i++)
			if (nums[i] != i + 1)
				return i + 1;
		return n + 1;
	}
};