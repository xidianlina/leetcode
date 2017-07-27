/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5

本题要求求解的是两个有序序列的中位数。本质上就是求两个有序序列“第k小的数“的变形。
假设两个有序序列一个长为m,另一个长为n，则我们要求的就是第（m+n）/2+1个数，
若m+n为偶数，则求的是第(m+n)/2和第(m+n)/2+1个数的平均数。

接下来分析如何在O(log(m+n))的复杂度内求解第k个小的数。
我们首先假设k为偶数并且两个有序序列a,b的长度都大于k/2（边界情况见代码），比较a[k/2-1]和b[k/2-1]的大小：
1.若a[k/2-1]==b[k/2-1]，则该值就是我们所要求的值，
  因为将a和b的前k/2个元素归并后就获得了a，b序列的前k个元素，并且a[k/2-1]和b[k/2-1]相等且在最末尾。
2.若a[k/2-1]<b[k/2-1]，则a的前k/2个元素中并不包含我们所求的第k小的元素，因此我们可以将其舍弃，
  进而递归求解剩下这些元素的第(k-k/2)小的元素。
3.若a[k/2-1]>b[k/2-1]，处理方法和情况2类似
复杂度分析:我们在求解第k小的元素的每次递归的过程中，基本上每次都要舍弃接近k/2的元素，
而k的初始值为(m+n)/2，因为算法的复杂度为O(log(m+n))
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int size_1 = nums1.size();
		const int size_2 = nums2.size();
		int k = (size_1 + size_2) / 2;
		int res1 = Kth(nums1.begin(), size_1, nums2.begin(), size_2, k + 1);
		if ((size_1 + size_2) % 2 == 0) {
			int res2 = Kth(nums1.begin(), size_1, nums2.begin(), size_2, k);
			return ((double)res1 + res2) / 2.0;
		}
		return res1;
	}
private:
	typedef vector<int>::iterator Iter;

	int  Kth(Iter start1, int size_1, Iter start2, int size_2, int kth) {
		if (size_1 > size_2)
			return Kth(start2, size_2, start1, size_1, kth);
		if (size_1 == 0)
			return *(start2 + kth - 1);
		if (kth == 1)
			return min(*start1, *start2);

		int index_1 = min(size_1, kth / 2);
		int index_2 = kth - index_1;
		if (*(start1 + index_1 - 1) > *(start2 + index_2 - 1))
			return Kth(start1, size_1, start2 + index_2, size_2 - index_2, kth - index_2);
		return Kth(start1 + index_1, size_1 - index_1, start2, index_2, kth - index_1);
	}
};