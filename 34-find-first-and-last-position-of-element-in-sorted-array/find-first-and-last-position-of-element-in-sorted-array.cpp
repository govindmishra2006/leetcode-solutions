class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        int smallest = -1;
        int largest = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                smallest = mid;
                largest = mid;
                int low2 = mid + 1;
                int high2 =  mid -1;
                while(low <= high2){
                    int mid2 = (low + high2)/2;
                    if(nums[mid2] == target){
                        smallest = mid2;
                        high2 = mid2 - 1;
                    }
                    else if(nums[mid2] < target){
                        low = mid2 + 1;
                    }
                    else{
                        high2 = mid2 -1;
                    }
                }
                while(low2 <= high){
                    int mid3 = (low2 + high)/2;
                    if(nums[mid3] == target){
                        largest = mid3;
                        low2 = mid3 + 1;
                    }
                    else if(nums[mid3] <target){
                        low2 = mid3 + 1;
                    }
                    else{
                        high = mid3 - 1;
                    }
                }
                return {smallest,largest};
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return {-1,-1};
    }
};