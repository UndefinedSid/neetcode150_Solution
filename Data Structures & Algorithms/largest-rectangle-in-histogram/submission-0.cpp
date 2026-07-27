class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxi=0;

        for(int i=0;i<n;i++){
            int currHeight=heights[i];

            while(! st.empty() && currHeight < heights[st.top()]){
                int ht=heights[st.top()];
                st.pop();
                int width=(st.empty()) ? i : i-st.top()-1;
                maxi=max(maxi,width * ht);

            }
            st.push(i);
        }

        while(!st.empty()){
            int ht=heights[st.top()];
            st.pop();
            int width=(st.empty()) ? n : n-st.top()-1;
            maxi=max(maxi,width * ht);
        }

        return maxi;           
    }
};
