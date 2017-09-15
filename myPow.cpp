/*
Implement pow(x, n).
*/

class Solution {
public:
	//����x^2n = (x^n)*(x^n),  x^2n+1 = (x^n)*(x^n)*x ע��n�Ǹ���������ȡ��ʱ�����ܻ����
	double myPow(double x, int n) {
		double res = 1.0;
		//ʹ��long long��Ҫ��ֹn = -2147483648ʱ��ȡ�����
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