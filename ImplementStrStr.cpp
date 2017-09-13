/*
Implement strStr()
Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
ʵ��strstr(). ����needle(�ؼ���)��haystack(�ַ���)�е�һ�γ��ֵ�λ�ã����needle����haystack�У��򷵻�-1��
ע��strstr()��c++�е�һ������
*/

#include <string>

using namespace std;

class Solution {
public:
	/*
	��ԭ����ÿһ������Ϊm���ִ����ж��Ƿ��ƥ�䴮һ�¡��ܹ���n-m+1���Ӵ���
	�����㷨ʱ�临�Ӷ�ΪO((n-m+1)*m)=O(n*m)���ռ临�Ӷ���O(1)��
	*/
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		int m = haystack.size(), n = needle.size();
		if (m < n)
			return -1;
		for (int i = 0; i <= m - n; i++)
		{
			int j;
			for (j = 0; j < n; j++)
				if (haystack[i + j] != needle[j])
					break;
			if (j == n)
				return i;
		}
		return -1;
	}
};