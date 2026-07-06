class Solution {
   public:
   using ll=long long;
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int st = 1, end = *max_element(piles.begin(), piles.end());

        int ans=end;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            ll time = 0;
            for (int i = 0; i < n; i++) {
                if (piles[i] <= mid) {
                    time++;
                } else {
                    time += (ll)(piles[i] + mid - 1) / mid;
                }
            }
            if (time > h) {
                st = mid + 1;
            } else {
                ans=mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};