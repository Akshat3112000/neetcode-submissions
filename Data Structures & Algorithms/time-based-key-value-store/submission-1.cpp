class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string k, string v, int t) {
        mp[k].push_back({t,v});
    }
    
    string get(string k, int t) {
        vector<pair<int,string>> v = mp[k];
        int i = lower_bound(v.begin(),v.end(),make_pair(t + 1,"")) - v.begin();
        if(i == 0) return "";
        return v[i-1].second;
    }
};
