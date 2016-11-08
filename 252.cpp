/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct cmp{
    bool operator() (const Interval& a,const Interval& b){
        return a.start<b.start;
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& ins) {
        sort(ins.begin(),ins.end(),cmp());
        for (int i=1;i<ins.size();i++)
            if (ins[i].start<ins[i-1].end)
                return false;
        return true;
    }
};