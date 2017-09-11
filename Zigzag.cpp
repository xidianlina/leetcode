/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows)
	{
		int size = static_cast<int>(s.size());
		// ������С�ڵ���1 �� ����ԭ����sizeʱ����ת��
		if (numRows <= 1 || numRows >= size) {
			return s;
		}

		// �ַ�������, װ�����еĶ�Ӧ���ַ���
		vector <string> rowString(numRows);
		int rowNum = 1;
		// ���¶��������϶��ı�־
		int flag = 1;
		for (int i = 0; i < size; ++i) {
			rowString[rowNum - 1] += s[i];
			if (rowNum == numRows) {
				flag = -1;
			}
			if (rowNum == 1) {
				flag = 1;
			}
			rowNum += flag;
		}

		string result;
		for (int i = 0; i < numRows; ++i) {
			result += rowString[i];
		}
		return result;
	}

	string convert2(string s, int nRows) {
		if (nRows <= 1 || s.length() == 0)
			return s;

		string res = "";
		int len = s.length();
		for (int i = 0; i < len && i < nRows; ++i)
		{
			int indx = i;
			res += s[indx];

			for (int k = 1; indx < len; ++k)
			{
				//��һ�л����һ�У�ʹ�ù�ʽ2 * nRows - 2��  
				if (i == 0 || i == nRows - 1)
				{
					indx += 2 * nRows - 2;
				}
				//�м��У��ж���ż
				else
				{
					if (k & 0x1)  //����λ��ʹ�ù�ʽ2 * (nRows - 1 - i)
						indx += 2 * (nRows - 1 - i);
					else indx += 2 * i;//ż��λ��ʹ�ù�ʽ2 * i
				}

				//�ж�indx�Ϸ���  
				if (indx < len)
				{
					res += s[indx];
				}
			}
		}
		return res;
	}
};