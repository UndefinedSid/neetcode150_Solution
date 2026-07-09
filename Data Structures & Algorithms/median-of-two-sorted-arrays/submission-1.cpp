class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();

        if( nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);

        int l=0, r=m;
        while(l <= r){
            int p1=l + (r-l) / 2;
            int p2=(m+n+1) / 2 - p1;

            int l1=(p1==0) ? INT_MIN : nums1[p1-1];
            int l2=(p2==0) ? INT_MIN : nums2[p2-1];

            int r1=(p1==m) ? INT_MAX : nums1[p1];
            int r2=(p2==n) ? INT_MAX : nums2[p2];

            if(l1 <= r2 && l2 <= r1){

                if((m+n) % 2==1)
                    return max(l1,l2);
                else
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
            } 
            if(l1 > r2)
                r=p1-1;
            else
                l=p1+1;
        }
        return INT_MIN;
    }
};
