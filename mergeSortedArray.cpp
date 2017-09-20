/*
Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to 
hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (nums1.empty() || nums2.empty())
			return;
		int idx1 = m - 1;
		int idx2 = n - 1;
		int len = m + n - 1;
		while (idx1 >= 0 && idx2 >= 0) {
			if (nums1[idx1] >= nums2[idx2])
				nums1[len--] = nums1[idx1--];
			else
				nums1[len--] = nums2[idx2--];
		}
		while (idx2 >= 0)
			nums1[len--] = nums2[idx2--];
	}
};