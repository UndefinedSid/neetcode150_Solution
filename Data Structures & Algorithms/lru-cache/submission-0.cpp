class LRUCache {
public:

    list<int> dlList;
    int cap;
    map<int,pair<list<int>::iterator,int>> cacheMap;

    void makeRecentUsed(int key){
        dlList.erase(cacheMap[key].first);
        dlList.push_front(key);
        cacheMap[key].first=dlList.begin();
    }

    LRUCache(int capacity) {
        this->cap=capacity;
    }
    
    int get(int key) {
        if(cacheMap.count(key)){
            makeRecentUsed(key);
            return cacheMap[key].second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cacheMap.count(key)){
            cacheMap[key].second=value;
            makeRecentUsed(key);
        }else{
            dlList.push_front(key);
            cacheMap[key]={dlList.begin(),value};
            cap--;
        }

        if(cap < 0){
            cacheMap.erase(dlList.back());
            dlList.pop_back();
            cap++;
        }
    }
};
