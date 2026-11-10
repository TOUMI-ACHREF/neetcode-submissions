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
        double current_rest = (double)(target - cars[0].first) / cars[0].second;
        st.push(current_rest);
        for(int i = 1; i < cars.size(); i++){
            current_rest = (double)(target - cars[i].first) / cars[i].second;
            if (st.top() < current_rest) st.push(current_rest);
        }
        return st.size();

    }
};
