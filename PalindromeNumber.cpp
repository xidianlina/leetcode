/*
Palindrome Number:
Determine whether an integer is a palindrome. 
Do this without extra space.
题目要求只能用O(1)的空间，所以不能考虑把它转化为字符串然后reverse比较的方法。
*/

class Solution {
public:
	bool isPalindrome(int x) {
		//negative number
		if (x < 0)
			return false;

		int len = 1;
		while (x / len >= 10)
			len *= 10;

		while (x > 0) {
			//get the head and tail number
			int left = x / len;
			int right = x % 10;

			if (left != right)
				return false;
			else {
				//remove the head and tail number
				x = (x % len) / 10;
				len /= 100;
			}
		}
		return true;
	}
};