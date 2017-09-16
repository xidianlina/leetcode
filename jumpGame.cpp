/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
Note:
You can assume that you can always reach the last index.
给定一个数组，每个元素代表从该位置可以跳过的距离，问从第一个位置跳到最后一个位置至少需要跳多少次。
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*fuction first
	res:目前为止的jump数
	curRch:从A[0]进行ret次jump之后达到的最大范围
	curMax:从0~i这i+1个A元素中能达到的最大范围
	当curRch < i，说明ret次jump已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到记录的curMax。
	*/
	int jump(vector<int>& nums) {
        int n=nums.size();
        int res = 0;
        int curMax = 0;
        int curRch = 0;
        for(int i = 0; i < n; i ++)
        {
            if(curRch < i)
            {
                res ++;
                curRch = curMax;
            }
            curMax = max(curMax, nums[i]+i);
        }
        return res;
    }
	
	//fuction second
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