class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> carMap;
        int n=position.size();

        stack<double> st;

        for(int i=0;i<n;i++){
            double time=(double) (target - position[i]) / speed[i];
            carMap.push_back({position[i],time});
        }

        sort(carMap.rbegin(),carMap.rend());

        for(int i=0;i<n;i++){
            double currTime=carMap[i].second;

            if(st.empty() || currTime > st.top())
                st.push(currTime);

        }

        return st.size();

        // int ans=0;
        // double maxTime=0.0;

        // for(int i=0;i<n;i++){
        //     if(carMap[i].second > maxTime){
        //         maxTime=carMap[i].second;
        //         ans++;
        //     }
        // }
        // return ans;
    }
};
