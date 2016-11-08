/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct IntervalCmp{
    bool operator () (const Interval& a, const Interval& b) const {
        return a.end<b.end;
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int lastEnd=numeric_limits<int>::min();
        sort(intervals.begin(),intervals.end(),IntervalCmp());
        for (int i=0;i<intervals.size();i++) {
            if (intervals[i].start<lastEnd)
                return false;
            lastEnd=intervals[i].end;
        }
        return true;
    }
};