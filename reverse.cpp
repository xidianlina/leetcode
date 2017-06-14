/*
Reverse Integer

Reverse digits of an integer
Example1: x = 123, return 321
Example2: x = -123, return -321
*/
//#include <iostream>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int reverse(int x)
//	{
//		long res = 0;
//		while (x)
//		{
//			res = res * 10 + x % 10;
//			x /= 10;
//		}
//		return (res<INT_MIN || res>INT_MAX) ? 0 : res;
//	}
//};
//
//int main()
//{
//	Solution fun;
//	cout << fun.reverse(-321) << endl;
//
//	return 0;
//}