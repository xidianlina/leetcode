/*
Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution
//{
//public:
//	vector<int> twoSum(vector<int>&nums, int target)
//	{
//		unordered_map<int, int> hash;
//		vector<int> result;
//		for (unsigned int i = 0; i < nums.size(); i++)
//		{
//			int numToFind = target - nums[i];
//			if (hash.find(numToFind) != hash.end())
//			{
//				result.push_back(hash[numToFind]);
//				result.push_back(i);
//			}
//			hash[nums[i]] = i;
//		}
//		return result;
//	}
//
//	vector<int> findTwoSum(vector<int> &nums, int target)
//	{
//		unordered_map<int, int> map;
//		for (unsigned int i = 0; i < nums.size();i++)
//		{
//			auto p = map.find(target - nums[i]);
//			if (p != map.end())
//				return { p->second,int(i) };
//			map[nums[i]] = i;
//		}		
//	}
//};
//
//int main()
//{
//	vector<int> vect = { 2,6,3,5,8 };
//	int target = 11;
//	Solution fun;
//	vector<int> res = fun.twoSum(vect, target);
//	vector<int> result = fun.findTwoSum(vect, target);
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << endl;
//
//	for (int i = 0; i < result.size(); i++)
//		cout << result[i] << endl;
//
//	return 0;
//}