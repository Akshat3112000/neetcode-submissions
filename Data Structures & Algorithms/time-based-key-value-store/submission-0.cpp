class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string k, string v, int t) {
        mp[k].push_back({t,v});
    }
    
    string get(string k, int t) {
        int i = lower_bound(mp[k].begin(),mp[k].end(),make_pair(t + 1,"")) - mp[k].begin();
        if(i == 0) return "";
        return mp[k][i-1].second;
    }
};
