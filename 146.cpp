struct Node {
    int key;
    int value;
    Node(int k,int v):key(k),value(v){};
};
class LRUCache{
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=iteMap.find(key);
        if (it==iteMap.end())
            return -1;
        else {
            auto listIte=it->second;
            cache.splice(cache.begin(),cache,listIte);
            iteMap.erase(key);
            iteMap[key]=cache.begin();
            return cache.front().value;
        }
    }
    
    void set(int key, int value) {
        auto it=iteMap.find(key);
        if (it==iteMap.end()) {
            if (cache.size()==cap) {
                iteMap.erase(cache.back().key);
                cache.pop_back();
                cache.push_front(Node(key,value));
                iteMap[key]=cache.begin();
            } else {
                cache.push_front(Node(key,value));
                iteMap[key]=cache.begin();
            }
        } else {
            auto listIte=it->second;
            cache.splice(cache.begin(),cache,listIte);
            iteMap.erase(key);
            iteMap[key]=cache.begin();
            cache.front().value=value;
        }
    }
private:
    int cap;
    list<Node> cache;
    unordered_map<int,list<Node>::iterator> iteMap;
};