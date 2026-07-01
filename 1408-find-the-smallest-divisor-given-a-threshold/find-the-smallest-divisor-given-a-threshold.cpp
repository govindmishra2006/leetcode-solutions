class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_val = INT_MIN;
        int sum = 0;
        int min_sum = 0;
        int ans;
        for(int i = 0;i<n;i++){
            max_val = max(nums[i],max_val);
        }
        int high = max_val;
        int low = 1;
        while(low <= high){
            int mid = (high + low)/2;
            sum = 0;
            for(int i=0;i<n;i++){
                sum  = sum + (nums[i] + mid - 1)/mid;
            }
            if(sum > threshold){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};