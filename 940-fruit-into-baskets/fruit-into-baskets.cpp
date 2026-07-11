class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mpp;
        int l = 0;
        int r = 0;
        int length = 0;
        int maxLength = 0;
        while (r < n) {
            if (mpp.find(fruits[r]) != mpp.end()) {
                mpp[fruits[r]]++;
            } else if (mpp.empty() || (mpp.find(fruits[r]) == mpp.end())) {
                mpp[fruits[r]]++;
            }
            
            if (mpp.size() > 2) {
                while (mpp.size() > 2) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0)
                        mpp.erase(fruits[l]);
                    l++;
                }
            }
            length = r - l + 1;
            maxLength = max(length, maxLength);
            r++;
        }
        return maxLength;
    }
};