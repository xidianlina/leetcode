/*
Remove Duplicates from Sorted Array II
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n<3)
			return n;
		int index = 2;
		for (int i = 2; i<n; i++)
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		return index;
	}
};