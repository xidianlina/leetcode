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

����Ҫ�������������������е���λ���������Ͼ����������������С���kС�������ı��Ρ�
����������������һ����Ϊm,��һ����Ϊn��������Ҫ��ľ��ǵڣ�m+n��/2+1������
��m+nΪż����������ǵ�(m+n)/2�͵�(m+n)/2+1������ƽ������

���������������O(log(m+n))�ĸ��Ӷ�������k��С������
�������ȼ���kΪż������������������a,b�ĳ��ȶ�����k/2���߽���������룩���Ƚ�a[k/2-1]��b[k/2-1]�Ĵ�С��
1.��a[k/2-1]==b[k/2-1]�����ֵ����������Ҫ���ֵ��
  ��Ϊ��a��b��ǰk/2��Ԫ�ع鲢��ͻ����a��b���е�ǰk��Ԫ�أ�����a[k/2-1]��b[k/2-1]���������ĩβ��
2.��a[k/2-1]<b[k/2-1]����a��ǰk/2��Ԫ���в���������������ĵ�kС��Ԫ�أ�������ǿ��Խ���������
  �����ݹ����ʣ����ЩԪ�صĵ�(k-k/2)С��Ԫ�ء�
3.��a[k/2-1]>b[k/2-1]�������������2����
���Ӷȷ���:����������kС��Ԫ�ص�ÿ�εݹ�Ĺ����У�������ÿ�ζ�Ҫ�����ӽ�k/2��Ԫ�أ�
��k�ĳ�ʼֵΪ(m+n)/2����Ϊ�㷨�ĸ��Ӷ�ΪO(log(m+n))
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