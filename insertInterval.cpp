/*
Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s,int e):start(s),end(e){}
};

class Solution {
public:
	/*
	如果新区间的末尾小于当前区间的开头，则跳出循环
	如果新区间的开头大于当前区间的末尾，不作处理
	如果新区间和当前区间有重叠，则更新新区间的开头为两者最小值，新区间的末尾为两者最大值，重叠数加一
	指针移向下一个区间
	如果重叠数大于0，则删除掉所有的重叠区间
	插入新区间到对应的位置
	*/
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res = intervals;
		int i = 0, overlap = 0, n = res.size();
		while (i < n) {
			if (newInterval.end < res[i].start)
				break;
			else if (newInterval.start > res[i].end) {}
			else {
				newInterval.start = min(newInterval.start, res[i].start);
				newInterval.end = max(newInterval.end, res[i].end);
				++overlap;
			}
			++i;
		}
		if (overlap > 0) 
			res.erase(res.begin() + i - overlap, res.begin() + i);
		res.insert(res.begin() + i - overlap, newInterval);
		return res;
	}
};