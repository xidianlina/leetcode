/*
Implement pow(x, n).
*/

class Solution {
public:
	//利用x^2n = (x^n)*(x^n),  x^2n+1 = (x^n)*(x^n)*x 注意n是负数，对其取反时，可能会溢出
	double myPow(double x, int n) {
		double res = 1.0;
		//使用long long主要防止n = -2147483648时，取反溢出
		long long nn = n;
		if (nn < 0)
			nn = -nn;
		while (nn != 0)
		{
			if (nn & 1)
				res *= x;
			nn >>= 1;
			x *= x;
		}
		if (n > 0)
			return res;
		else return 1 / res;
	}
};