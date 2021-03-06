/*
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, 
compute how much water it is able to trap after raining.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//function first
	int trap(vector<int>& height) {
		int res = 0, mx = 0, n = height.size();
		vector<int> dp(n, 0);
		for (int i = 0; i < n; ++i) {
			dp[i] = mx;
			mx = max(mx, height[i]);
		}
		mx = 0;
		for (int i = n - 1; i >= 0; --i) {
			dp[i] = min(dp[i], mx);
			mx = max(mx, height[i]);
			if (dp[i] > height[i]) res += dp[i] - height[i];
		}
		return res;
	}

	//function second
	int trap2(vector<int>& height) {
		int res = 0, l = 0, r = height.size() - 1;
		while (l < r) {
			int mn = min(height[l], height[r]);
			if (mn == height[l]) {
				++l;
				while (l < r && height[l] < mn) {
					res += mn - height[l++];
				}
			}
			else {
				--r;
				while (l < r && height[r] < mn) {
					res += mn - height[r--];
				}
			}
		}
		return res;
	}
};