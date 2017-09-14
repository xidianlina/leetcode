/*
Search for a Range
Given an array of integers sorted in ascending order,
find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		//时间复杂度为O(logn)
		int n = nums.size();
		int l = 0, h = n, m;
		int start = -1, end = -1;
		while (l<h) {
			m = l + ((h - l) >> 1);
			if (nums[m]>target) {
				h = m;
			}
			else if (nums[m]<target) {
				l = m + 1;
			}
			else {//找到以后，需要确定前后边界
				int index = m;
				while (index >= 0 && nums[index] == target)					
					index--;
				start = index + 1;
				index = m;
				while (index<n&&nums[index] == target)
					index++;
				end = index - 1;
				break;
			}
		}
		vector<int> res;
		res.push_back(start);
		res.push_back(end);
		return res;
	}
};