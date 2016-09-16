class Solution {
public:

    bool isRectangleCover(vector<vector<int>>& rec) {
        set<pair<int,int> >maskSet;
        int minX=numeric_limits<int>::max();
        int minY=numeric_limits<int>::max();
        int maxX=numeric_limits<int>::min();
        int maxY=numeric_limits<int>::min();
        int n=rec.size();
        long long sumArea=0;
        for (int i=0;i<n;i++) {
            minX=min(rec[i][0],minX);
            maxX=max(rec[i][2],maxX);
            minY=min(rec[i][1],minY);
            maxY=max(rec[i][3],maxY);
            sumArea+=(rec[i][2]-rec[i][0])*(rec[i][3]-rec[i][1]);
            if (maskSet.count(make_pair(rec[i][0],rec[i][1]))!=0)
                maskSet.erase(make_pair(rec[i][0],rec[i][1]));
            else
                maskSet.insert(make_pair(rec[i][0],rec[i][1]));
                
            if (maskSet.count(make_pair(rec[i][0],rec[i][3]))!=0)
                maskSet.erase(make_pair(rec[i][0],rec[i][3]));
            else
                maskSet.insert(make_pair(rec[i][0],rec[i][3]));
                
            if (maskSet.count(make_pair(rec[i][2],rec[i][1]))!=0)
                maskSet.erase(make_pair(rec[i][2],rec[i][1]));
            else
                maskSet.insert(make_pair(rec[i][2],rec[i][1]));
                
            if (maskSet.count(make_pair(rec[i][2],rec[i][3]))!=0)
                maskSet.erase(make_pair(rec[i][2],rec[i][3]));
            else
                maskSet.insert(make_pair(rec[i][2],rec[i][3]));
        }
        if (maskSet.size()!=4||maskSet.count(make_pair(minX,minY))==0||maskSet.count(make_pair(minX,maxY))==0
            ||maskSet.count(make_pair(maxX,minY))==0||maskSet.count(make_pair(maxX,maxY))==0)
            return false;
        if (sumArea!=(maxX-minX)*(maxY-minY))
            return false;
        return true;
            
    }
};

//TLE Edition
class Solution {
public:
    bool checkOverlap(vector<int>& a, vector<int>& b) {
        if (abs(b[0]+b[2]-a[0]-a[2])<a[2]-a[0]+b[2]-b[0]&&abs(b[1]+b[3]-a[1]-a[3])<a[3]-a[1]+b[3]-b[1])
            return true;
        else   
            return false;
    }
    bool isRectangleCover(vector<vector<int>>& rec) {
        int minxNo=0, minyNo=0;
        int maxxNo=0, maxyNo=0;
        int n=rec.size();
        for (int i=1;i<n;i++)
            if (rec[i][0]<rec[minxNo][0]||rec[i][0]==rec[minxNo][0]&&rec[i][1]<rec[minxNo][1])
                minxNo=i;
        for (int i=1;i<n;i++)
            if (rec[i][1]<rec[minyNo][1]||rec[i][1]==rec[minyNo][1]&&rec[i][0]<rec[minyNo][0])
                minyNo=i;
        if (minxNo!=minyNo)
            return false;
      
         for (int i=1;i<n;i++)
            if (rec[i][2]>rec[maxxNo][2]||rec[i][2]==rec[maxxNo][2]&&rec[i][3]>rec[maxxNo][3])
                maxxNo=i;
        for (int i=1;i<n;i++)
            if (rec[i][3]>rec[maxyNo][3]||rec[i][3]==rec[maxyNo][3]&&rec[i][2]>rec[maxyNo][2])
                maxyNo=i;
        if (maxxNo!=maxyNo)
            return false;
  
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++) {
                if (checkOverlap(rec[i],rec[j]))
                    return false;           

         long long area=(rec[maxxNo][2]-rec[minxNo][0])*(rec[maxyNo][3]-rec[minyNo][1]);
         long long addArea=0;
         for (int i=0;i<n;i++)
            addArea+=(rec[i][2]-rec[i][0])*(rec[i][3]-rec[i][1]);
         if (area!=addArea)
            return false;

         return true;
            
    }
};