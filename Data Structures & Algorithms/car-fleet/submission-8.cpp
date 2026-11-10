class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        stack<double> st;
        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(),[](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;
        });
        st.push((double)(target - cars[0].first) / cars[0].second);
        for(int i = 1; i < cars.size(); i++){
            if (st.top() < (double)(target - cars[i].first) / cars[i].second) st.push((double)(target - cars[i].first) / cars[i].second);
        }
        return st.size();
    }
};
