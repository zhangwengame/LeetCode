class Solution {
public:
    void dfs(string now, map<string,multiset<string> >& route,vector<string> &ret){
        while(!route[now].empty()) {
            string next=*route[now].begin();
            route[now].erase(next);
            dfs(next,route,ret);
        }
        ret.push_back(now);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string,multiset<string> > route;
        for (auto ticket:tickets) {
            route[ticket.first].insert(ticket.second);
        }
        vector<string> ret;
        dfs("JFK",route,ret);   
        return vector<string>(ret.rbegin(),ret.rend());
    }
};