class Solution {
public:
    int lessThanGoal(vector<int> &nums,int goal)
    {
        if(goal < 0) return 0;
        int l = 0;
        int count = 0;
        int subCount = 0;
        unordered_map<int,int> mpp;
        for(int r=0;r<nums.size();r++)
        {
            if(mpp.find(nums[r]) == mpp.end()) count++;
            mpp[nums[r]]++;
            while(count > goal)
            {
                if(mpp[nums[l]] == 1)
                {
                    mpp.erase(nums[l]);
                    count--;
                }
                else
                {
                    mpp[nums[l]]--;
                }
                l++;
            }
            subCount += (r - l + 1);
        }
        return subCount;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return lessThanGoal(nums,k) - lessThanGoal(nums,k-1);
    }
};