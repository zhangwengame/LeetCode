class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> edge;
        vector<int> indegree(numCourses,0); 
        vector<int> ret;
        queue<int> topQueue;
        for (int i=0;i<prerequisites.size();i++){
            edge[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        for (int i=0;i<numCourses;i++)
            if (indegree[i]==0)
                topQueue.push(i);
        while (!topQueue.empty()){
            int now=topQueue.front();
            topQueue.pop();
            ret.push_back(now);
            for (int i=0;i<edge[now].size();i++) {
                indegree[edge[now][i]]--;
                if (indegree[edge[now][i]]==0)
                    topQueue.push(edge[now][i]);
            }
        }
        if (ret.size()!=numCourses)
            return vector<int>();
        else
            return ret;
    }
};