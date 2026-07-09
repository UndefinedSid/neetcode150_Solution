class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if( ! mp.count(key))
            return "";

        const auto& val =mp[key];
        int l=0, r=val.size()-1;
        string ans="";

        while(l <= r){
            int mid=l + (r-l) / 2;

            if(val[mid].second <= timestamp){
                ans=val[mid].first;
                l= mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};
