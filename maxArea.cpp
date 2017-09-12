/*
Container With Most Water
����n���Ǹ�����a1,a2,...,an������ÿ������һ�������꣨i,ai����
n����ֱ�߶������߶ε������˵��ڣ�i,ai���ͣ�i,0����
�ҵ������߶Σ���x���γ�һ��������ʹ���������ˮ��
��Ŀ����˼�ǣ������е�ÿ������Ӧһ���߶εĳ��ȣ�������Ӧx���꣬���������������һ���ײ��Ŀ�
�߶Ⱦ���ǰ����˵���߶εĳ��ȣ�����Ȼ��Ҫʢˮ���߶Ⱦ��������߶��н϶̵�һ����
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
			return 0;
		int res = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			int volumn = (right - left)*min(height[right] , height[left]);
			if (volumn > res)
				res = volumn;
			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return res;
	}
};