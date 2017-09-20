/*
Search in Rotated Sorted Array II
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Write a function to determine if a given target is in the array.
The array may contain duplicates.
*/

#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0 || nums.empty())
			return false;
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return true;
			if (nums[left] == nums[mid] && nums[mid] == nums[right])
			{
				++left;
				--right;
			}
			else if (nums[left] <= nums[mid])
			{
				if (nums[left] <= target&&target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			else {
				if (nums[mid] < target&&target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return false;
	}
};