class Solution {
public:
    long long hoursRequired(vector<int>& arr, int rate){

    long long hours = 0;

    for(int x : arr){

        hours += (x + rate - 1LL) / rate;

    }

    return hours;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int n = piles.size();
        int max_val = 0;
        for(int i=0;i<n;i++){
            max_val = max(max_val,piles[i]);
        }
        int high = max_val;
        while(low <= high){
            int mid = (low + high)/2;
            long long hours_required = hoursRequired(piles,mid);
            if(hours_required > h){
                low = mid + 1;
            }
            if(hours_required <= h){
                high = mid - 1;
            }
        }
        return low;
        
    }
};