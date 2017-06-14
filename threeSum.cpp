/*
Three Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

//#include <iostream>
//#include <vector>
//#include<algorithm>
//
//using namespace std;
//
//class Solution
//{
//public:
//	vector<vector<int>> threeSum(vector<int> &nums)
//	{
//		vector<vector<int>> res;
//		sort(nums.begin(), nums.end());
//		for (unsigned int i = 0; i < nums.size(); i++)
//		{
//			if (i > 0 && nums[i] == nums[i - 1])
//				continue;
//			int l = i + 1;
//			int r = nums.size()-1;
//			while (l < r)
//			{
//				int s = nums[i] + nums[l] + nums[r];
//				if (s > 0)
//					r--;
//				else if (s < 0)
//					l++;
//				else
//				{
//					res.push_back(vector<int> {nums[i], nums[l], nums[r]});
//					while (nums[l] == nums[l + 1])
//						l++;
//					while (nums[r] == nums[r - 1])
//						r--;
//					l++;
//					r--;
//				}
//			}
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	vector<int> vect = { -1,0,1,2,-1,-4 };
//	Solution s;
//	vector<vector<int>> res = s.threeSum(vect);
//	for (int i = 0; i < res.size(); i++)
//	{
//		for (auto p = res[i].begin(); p != res[i].end(); p++)
//			cout << *p << "\t";
//		cout << endl;
//	}
//
//	return 0;
//}