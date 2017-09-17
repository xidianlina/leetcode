/*
Sqrt(x)
Implement int sqrt(int x).
Compute and return the square root of x.
*/

class Solution {
public:
	//function first
	int mySqrt(int x) {
		long long left = 0;
		long long right = (x / 2) + 1;
		while (left <= right)
		{
			long long mid = (left + right) / 2;
			long long sq = mid*mid;
			if (sq == x)
				return mid;
			else if (sq < x)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return right;
	}

	//function second
	int mySqrt2(int x)
	{
		if (x == 0)
			return 0;
		double res = 1;
		double pre = 0;
		while (res != pre)
		{
			pre = res;
			res = (res + x / res) / 2;
		}
		return int(res);
	}
};