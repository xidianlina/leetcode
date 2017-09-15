/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
Note:
You can assume that you can always reach the last index.
����һ�����飬ÿ��Ԫ�ش���Ӹ�λ�ÿ��������ľ��룬�ʴӵ�һ��λ���������һ��λ��������Ҫ�����ٴΡ�
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0;
		int n = nums.size();
		int cur = 0;
		int i = 0;
		while (cur < n - 1)
		{
			int pre = cur;
			while (i <= pre)
			{
				cur = max(cur, i + nums[i]);
				++i;
			}
			++res;
			if (pre == cur)
				return -1;
		}
		return res;
	}
};