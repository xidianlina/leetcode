/*
Permutation Sequence
The set [1,2,3,бн,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		string num = "123456789";
		vector<int> f(n, 1);
		for (int i = 1; i < n; ++i) 
			f[i] = f[i - 1] * i;
		--k;
		for (int i = n; i >= 1; --i) {
			int j = k / f[i - 1];
			k %= f[i - 1];
			res.push_back(num[j]);
			num.erase(j, 1);
		}
		return res;
	}
};