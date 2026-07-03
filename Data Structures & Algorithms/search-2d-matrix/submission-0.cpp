class Solution {
public:
    /* // Intial thought approach -> O(col * log(row)) 

    bool binarySearch(vector<int>& arr,int target){
        int sz=arr.size();
        int l=0,r=sz-1;
        while(l <= r){
            int mid= l + (r - l) / 2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid] > target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        for(auto& vec : matrix){
            int n=vec.size();
            if(vec[0] <= target && vec[n-1] >= target)
               if(binarySearch(vec,target))
                    return true;
        }
        return false;
    }

    */

    // optimized approach -> O(log(row * col))

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int l=0,r=(row * col)-1;

        while(l <= r){
            int mid=l + (r-l) / 2;

            int ro=mid / col;
            int c=mid % col;

            if(matrix[ro][c]== target)
                return true;
            else if(matrix[ro][c] > target)
                r=mid - 1;
            else 
                l=mid + 1;

        }
        return false;
    }
};
