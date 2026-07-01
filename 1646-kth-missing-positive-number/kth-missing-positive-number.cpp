class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int range = n + k;
        int nth = 0;

        for (int i = 1; i <= range; i++) {
            auto it = find(arr.begin(), arr.end(), i);

            if (it == arr.end()) {
                nth++;
            }

            if (nth == k) {
                return i;
            }
        }

        return -1; 
    }
};