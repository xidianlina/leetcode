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
	/*fuction first
	res:ĿǰΪֹ��jump��
	curRch:��A[0]����ret��jump֮��ﵽ�����Χ
	curMax:��0~i��i+1��AԪ�����ܴﵽ�����Χ
	��curRch < i��˵��ret��jump�Ѿ������Ը��ǵ�ǰ��i��Ԫ�أ������Ҫ����һ��jump��ʹ֮�ﵽ��¼��curMax��
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