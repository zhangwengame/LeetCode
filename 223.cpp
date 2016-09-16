class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int intersect=0;
        if (abs(bx2+bx1-ax2-ax1)<ax2-ax1+bx2-bx1&&abs(by2+by1-ay2-ay1)<ay2-ay1+by2-by1) {
            int left=max(ax1,bx1);
            int down=max(ay1,by1);
            int right=min(ax2,bx2);
            int up=min(ay2,by2);
            intersect=(right-left)*(up-down);
        }
        return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-intersect;
    }
};