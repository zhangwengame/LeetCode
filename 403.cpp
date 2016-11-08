class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> possipleJump;
        vector<int> maxJump(stones.size(), 0);
        possipleJump[0].insert(0);
        int k = 0;
        for (int i = 1; i < stones.size(); ++i) {
            while (maxJump[k] + 1 < stones[i] - stones[k]) 
                ++k;
            for (int j = k; j < i; ++j) {
                int t = stones[i] - stones[j];
                if (possipleJump[j].count(t - 1) || possipleJump[j].count(t) || possipleJump[j].count(t + 1)) {
                    possipleJump[i].insert(t);
                    maxJump[i] = max(maxJump[i], t);
                }
            }
        }
        return maxJump.back() > 0;
    }
};