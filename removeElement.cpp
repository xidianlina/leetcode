/*
Remove Element
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example:
Given input array nums = [3,2,2,3], val = 3
Your function should return length = 2, with the first two elements of nums being 2.
把数组中与给定值相同的元素删除，在原数组上修改，返回值是最终元素个数。
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		int n = 0;
		for (int i = 0; i < len; i++)
			if (nums[i] != val)
				nums[n++] = nums[i];
		return n;
	}
};

int main()
{
	vector<int> nums{ 3,2,2,3 };
	Solution s;
	cout << s.removeElement(nums, 3) << endl;
	
	return 0;
}