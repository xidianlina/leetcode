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
	����������ĩβС�ڵ�ǰ����Ŀ�ͷ��������ѭ��
	���������Ŀ�ͷ���ڵ�ǰ�����ĩβ����������
	���������͵�ǰ�������ص��������������Ŀ�ͷΪ������Сֵ���������ĩβΪ�������ֵ���ص�����һ
	ָ��������һ������
	����ص�������0����ɾ�������е��ص�����
	���������䵽��Ӧ��λ��
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