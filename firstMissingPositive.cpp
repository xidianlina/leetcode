/*
First Missing Positive
Given an unsorted integer array, find the first missing positive integer.
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.
����һ�����飬�ҳ���һ��ȱʧ��������Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/

#include <vector>

using namespace std;

class Solution {
public:
	/*
	������n���ڵ�n-1��λ���ϣ������ӵ�һ��λ�ÿ�ʼ�����λ���ϵ���������λ�úţ�
	��ô���ǵ�һ��ȱʧ������
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