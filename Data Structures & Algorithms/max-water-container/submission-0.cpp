class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0;
        int r = n - 1;
        int ans = INT_MIN;

        while (l < r) {
            
            int temp = min(heights[l], heights[r]);
            int curr = temp * (r - l);
            ans = max(ans, curr);

            if(heights[l] < heights[r])
                l++;
            else if(heights[l]==heights[r]){
                l++;
                r--;
            }else
                r--;
            
        }
        return ans;
    }
};
