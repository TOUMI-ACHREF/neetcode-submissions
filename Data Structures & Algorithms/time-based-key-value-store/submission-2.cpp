class TimeMap {
private: unordered_map<string, vector<pair<string, int>>> timeMap;
public:

    TimeMap(): timeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(timeMap.find(key) != timeMap.end()) timeMap.find(key)->second.push_back({value, timestamp});
        else timeMap[key] = {{value, timestamp}};
    }
    
    string get(string key, int timestamp) {
        auto it = timeMap.find(key);
        if(it == timeMap.end()) return "";

        const auto& values = it->second;
        int l = 0;
        int r = static_cast<int>(values.size()) - 1;
        int mid=r;
        int last_valid = -1;
        while(l<=r){
            mid = l + (r-l)/2;
            if(values[mid].second == timestamp) return values[mid].first;
            else if(values[mid].second > timestamp) r = mid-1;
            else {
                last_valid = mid;
                l = mid+1;
            }
        }
        if (last_valid!=-1) return values[last_valid].first;
        else return "";
    }
};
