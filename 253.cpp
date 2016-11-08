
struct Node{
    int roomId;
    int endTime;
    Node():roomId(0),endTime(0){}
    Node(int r,int e):roomId(r),endTime(e){}
};
struct IntervalCmp{
    bool operator () (const Interval& a, const Interval& b) const {
        if (a.start==b.start)
            return a.end<b.end;
        else
            return a.start<b.start;
    }
};
struct NodeCmp{
    bool operator () (const Node& a, const Node& b) const {
        return a.endTime>b.endTime;
    }
};
class Solution {
public:

    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),IntervalCmp());
        priority_queue<Node,vector<Node>,NodeCmp> roomQueue;
        int roomCount=0;
        int minimumEndTime=std::numeric_limits<int>::max();
        for (int i=0;i<intervals.size();i++){
            if (minimumEndTime>intervals[i].start) {
                roomCount++;
                roomQueue.push(Node(roomCount,intervals[i].end));
            } else {
                Node now=roomQueue.top();
                roomQueue.pop();
                roomQueue.push(Node(now.roomId,intervals[i].end));
            }
            minimumEndTime=roomQueue.top().endTime;
        }
        return roomCount;
    }
};