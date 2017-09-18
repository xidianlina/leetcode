/*
Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//function first
	void sortColors(vector<int>& nums) {
		int len = nums.size();
		int r = 0;
		int w = 0;
		int b = 0;
		for (int i = 0; i < len; i++)
		{
			if (0 == nums[i])
				r++;
			else if (1 == nums[i])
				w++;
			else
				b++;
		}
		for (int i = 0; i < len; i++)
		{
			if (i < r)
				nums[i] = 0;
			else if (i < r + w)
				nums[i] = 1;
			else
				nums[i] = 2;
		}
	}

	//function second
	void sortColors2(vector<int> &nums)
	{
		int n = nums.size();
		int left = 0;  //left记录第一个1的位置，left左边为0
		int right = n - 1;  //right记录第一个非2的位置，right右边为2
		int i = 0;
		while (i <= right)
		{
			if (nums[i] == 0)
			{
				swap(nums[left], nums[i]);
				left++;
				i++;
			}
			else if (nums[i] == 1)
			{
				i++;
			}
			else
			{
				swap(nums[i], nums[right]);
				right--;
			}
		}
	}
};