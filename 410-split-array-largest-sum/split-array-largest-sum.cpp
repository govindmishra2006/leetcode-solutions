class Solution {
public:
    int largestSum(vector<int> &arr,int sum){
        int elements = 1;
        int subsum = 0;
        for(int i=0;i<arr.size();i++){
            if(subsum + arr[i] <= sum){
                subsum += arr[i];
            }
            else{
                elements += 1;
                subsum = arr[i]; 
            }
        }
        return elements;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n){
            return -1;
        }
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(largestSum(nums,mid) <= k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};