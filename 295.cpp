class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        bool smallerThanBig=bigHalf.empty()||num<=bigHalf.top();
        bool biggerThanSmall=smallHalf.empty()||num>=smallHalf.top();
        if (!smallerThanBig)
            bigHalf.push(num);
        else if (!biggerThanSmall)
            smallHalf.push(num);
        else {
            if (smallHalf.size()<bigHalf.size())
                smallHalf.push(num);
            else
                bigHalf.push(num);
        }
        if (bigHalf.size()-2==smallHalf.size()) {
            int tmp=bigHalf.top();
            bigHalf.pop();
            smallHalf.push(tmp);
        }
        if (smallHalf.size()-2==bigHalf.size()) {
            int tmp=smallHalf.top();
            smallHalf.pop();
            bigHalf.push(tmp);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int sSize=smallHalf.size();
        int bSize=bigHalf.size();
        if (sSize>bSize)
            return smallHalf.top();
        else if (sSize<bSize)
            return bigHalf.top();
        else
            return (smallHalf.top()+bigHalf.top())*0.5;
    }
private:
    priority_queue<int,vector<int>,greater<int> > bigHalf;
    priority_queue<int,vector<int>,less<int> > smallHalf;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();