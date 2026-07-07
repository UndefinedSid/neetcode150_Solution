class Solution {
public:
    int findMin(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        int l=0,r=n-1;

        while(l < r){
            int mid=l + (r-l) / 2; // recommended 

            if(nums[mid] > nums[r])
                l=mid+1;
            else 
                r=mid;

        }
        return nums[l];   // nums[r]==nums[l]
    }
};
