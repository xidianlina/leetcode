/*
Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//fuction first
	int maxSubArray(vector<int>& nums) {
		int res = INT_MIN;
		int curSum = 0;
		for (int num : nums)
		{
			curSum = max(curSum + num, num);
			res = max(res, curSum);
		}
		return res;
	}

	//fuction second
	int maxSubArray2(vector<int>& nums) {
		int len = nums.size();
		if (len < 0 || nums.empty())
			return -1;
		int sum = nums[0];
		int curSum = nums[0];
		for (int i = 1; i < len; i++)
		{
			if (curSum <= 0)
				curSum = nums[i];
			else
				curSum+=nums[i];
			if (curSum > sum)
				sum = curSum;
		}
		return sum;
	}
};