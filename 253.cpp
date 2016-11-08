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
    int minMeetingRooms(vector<Interval>& ins) {
         sort(ins.begin(),ins.end(),cmp());
         priority_queue<int,vector<int>,greater<int>> rooms;
         for (int i=0;i<ins.size();i++) {
             if (rooms.size()==0) {
                 rooms.push(ins[i].end);
                 continue;
             } else {
                 int minTime=rooms.top();
                 if (minTime<=ins[i].start) {
                     rooms.pop();
                     rooms.push(ins[i].end);
                 } else {
                     rooms.push(ins[i].end);
                 }
             }
         }
         return rooms.size();
    }
};
