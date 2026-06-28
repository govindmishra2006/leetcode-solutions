class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int high = n-1;
        int ans = INT_MAX;
        int low = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[mid]){
                ans = min(nums[low],ans);
                low = mid + 1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};